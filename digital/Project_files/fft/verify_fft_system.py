#!/usr/bin/env python3
"""
FFT System Verification Script
Calculates expected FFT outputs for test signals to verify simulation results
"""

import numpy as np
import sys

# Constants
FFT_SIZE = 256
Q_FORMAT = 23  # Q1.23 fixed-point
MAX_VAL = 2**(Q_FORMAT)

def float_to_fixed(val, q_bits=Q_FORMAT):
    """Convert floating point to Q1.23 fixed-point"""
    fixed = int(val * (2**q_bits))
    # Clamp to 24-bit signed range
    if fixed > 8388607:
        fixed = 8388607
    elif fixed < -8388608:
        fixed = -8388608
    return fixed

def fixed_to_float(val, q_bits=Q_FORMAT):
    """Convert Q1.23 fixed-point to floating point"""
    return float(val) / (2**q_bits)

def generate_sine_wave(bin_num, amplitude):
    """Generate sine wave for specific FFT bin"""
    omega = 2 * np.pi * bin_num / FFT_SIZE
    samples = []
    for i in range(FFT_SIZE):
        sample = amplitude * np.sin(omega * i)
        samples.append(float_to_fixed(sample))
    return np.array(samples, dtype=np.int32)

def generate_dc_signal(amplitude):
    """Generate DC signal"""
    return np.full(FFT_SIZE, float_to_fixed(amplitude), dtype=np.int32)

def generate_two_tone(bin1, bin2, amp1, amp2):
    """Generate two-tone signal"""
    omega1 = 2 * np.pi * bin1 / FFT_SIZE
    omega2 = 2 * np.pi * bin2 / FFT_SIZE
    samples = []
    for i in range(FFT_SIZE):
        sample = amp1 * np.sin(omega1 * i) + amp2 * np.sin(omega2 * i)
        samples.append(float_to_fixed(sample))
    return np.array(samples, dtype=np.int32)

def compute_fft_float(samples):
    """Compute FFT using numpy (floating point reference)"""
    # Convert fixed-point to float
    float_samples = [fixed_to_float(s) for s in samples]

    # Compute FFT
    fft_result = np.fft.fft(float_samples)

    return fft_result

def analyze_fft_result(fft_result, test_name, expected_bin=None):
    """Analyze and display FFT results"""
    print(f"\n{'='*80}")
    print(f"{test_name} - Expected FFT Analysis")
    print(f"{'='*80}")

    if expected_bin is not None:
        print(f"Expected peak at bin {expected_bin}")

    print(f"\n{'Bin':>4} | {'Real':>12} | {'Imaginary':>12} | {'Magnitude':>12}")
    print("-" * 60)

    # Find peak
    magnitudes = np.abs(fft_result)
    max_bin = np.argmax(magnitudes[:FFT_SIZE//2])  # Only check first half
    max_magnitude = magnitudes[max_bin]

    # Display significant bins and expected bin
    for i in range(min(64, FFT_SIZE//2)):  # Show first 64 bins
        mag = magnitudes[i]
        real = fft_result[i].real
        imag = fft_result[i].imag

        # Show if magnitude is significant or if it's the expected bin
        if mag > 0.01 or i == expected_bin or i == max_bin:
            marker = ""
            if i == expected_bin:
                marker = " <- Expected"
            if i == max_bin:
                marker += " <- Peak"

            print(f"{i:4d} | {real:12.4f} | {imag:12.4f} | {mag:12.4f}{marker}")

    print(f"\n*** Peak detected at bin {max_bin} with magnitude {max_magnitude:.2f} ***")

    # Verify peak location
    if expected_bin is not None:
        if abs(max_bin - expected_bin) <= 1:  # Allow ±1 bin tolerance
            print(f"✓ SUCCESS: Peak at correct bin (within tolerance)")
        else:
            print(f"✗ ERROR: Peak at wrong bin! Expected {expected_bin}, got {max_bin}")

    print(f"{'='*80}\n")

    return max_bin, max_magnitude

def main():
    print("\n" + "="*80)
    print("FFT System Verification - Expected Output Calculator")
    print("="*80)
    print(f"FFT Size: {FFT_SIZE}")
    print(f"Fixed-Point Format: Q1.{Q_FORMAT}")
    print(f"="*80 + "\n")

    # Test 1: Single frequency sine wave at bin 16
    print("\n" + "="*80)
    print("TEST 1: Single Frequency Sine Wave (Bin 16)")
    print("="*80)
    amplitude = 0.5  # Half max amplitude
    samples = generate_sine_wave(16, amplitude)
    print(f"Generated {len(samples)} samples")
    print(f"Sample range: [{samples.min()}, {samples.max()}]")
    print(f"First 10 samples: {samples[:10]}")

    fft_result = compute_fft_float(samples)
    analyze_fft_result(fft_result, "Test 1 - Sine Wave Bin 16", expected_bin=16)

    # Test 2: DC Signal
    print("\n" + "="*80)
    print("TEST 2: DC Signal")
    print("="*80)
    amplitude = 0.25  # Quarter max amplitude
    samples = generate_dc_signal(amplitude)
    print(f"Generated {len(samples)} samples")
    print(f"DC value: {samples[0]} (fixed-point), {fixed_to_float(samples[0]):.4f} (float)")

    fft_result = compute_fft_float(samples)
    analyze_fft_result(fft_result, "Test 2 - DC Signal", expected_bin=0)

    # Test 3: Two-tone signal
    print("\n" + "="*80)
    print("TEST 3: Two-Tone Signal (Bins 16 and 32)")
    print("="*80)
    amp1 = 0.25
    amp2 = 0.25
    samples = generate_two_tone(16, 32, amp1, amp2)
    print(f"Generated {len(samples)} samples")
    print(f"Sample range: [{samples.min()}, {samples.max()}]")

    fft_result = compute_fft_float(samples)
    max_bin, _ = analyze_fft_result(fft_result, "Test 3 - Two-Tone Signal", expected_bin=16)

    # Check for second peak
    magnitudes = np.abs(fft_result)
    print("Other significant peaks:")
    for i in range(FFT_SIZE//2):
        if magnitudes[i] > 10 and i != max_bin:
            print(f"  Bin {i}: magnitude {magnitudes[i]:.2f}")

    # Summary
    print("\n" + "="*80)
    print("SUMMARY")
    print("="*80)
    print("Expected FFT peaks:")
    print("  Test 1 (Sine, Bin 16): Bin 16 should show peak magnitude ~128")
    print("  Test 2 (DC Signal):     Bin 0 should show peak magnitude ~64")
    print("  Test 3 (Two-Tone):      Bins 16 and 32 should both show peaks ~64")
    print("\nNotes:")
    print("  - Magnitudes are normalized by FFT_SIZE for numpy FFT")
    print("  - Actual FPGA FFT may have different scaling")
    print("  - Allow ±1 bin tolerance for peak detection")
    print("  - Fixed-point quantization may cause slight magnitude differences")
    print("="*80 + "\n")

if __name__ == "__main__":
    main()

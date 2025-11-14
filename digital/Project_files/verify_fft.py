import numpy as np

# Test 1: Sine wave at bin 16, amplitude 8388607/4 = 2097151.75
N = 256
bin_freq = 16
amplitude = 8388607 // 4

t = np.arange(N)
signal = amplitude * np.sin(2 * np.pi * bin_freq * t / N)
fft_out = np.fft.fft(signal)

# With 8 stages of /2 scaling, output is scaled by 2^8 = 256
expected_scale = 256

print("Test 1: Sine wave at bin 16")
print(f"Input amplitude: {amplitude}")
print(f"Expected scaling factor: {expected_scale}")
for i in [0, 16, 48, 80, 112, 144, 176, 208, 240]:
    mag = np.abs(fft_out[i]) / expected_scale
    print(f"Bin {i:3d}: magnitude = {mag:12.1f} (real={fft_out[i].real/expected_scale:10.1f}, imag={fft_out[i].imag/expected_scale:10.1f})")

print("\n")

# Test 2: DC signal, all values = 4194303
signal_dc = np.ones(N) * 4194303
fft_dc = np.fft.fft(signal_dc)
print("Test 2: DC signal")
print(f"Bin 0: magnitude = {np.abs(fft_dc[0])/expected_scale:12.1f}")
print(f"Bin 1: magnitude = {np.abs(fft_dc[1])/expected_scale:12.1f}")

print("\n")

# Test 3: Two tones at bins 16 and 64
amp1 = 8388607 // 8
amp2 = 8388607 // 8
signal2 = amp1 * np.sin(2 * np.pi * 16 * t / N) + amp2 * np.sin(2 * np.pi * 64 * t / N)
fft_2tone = np.fft.fft(signal2)
print("Test 3: Two tones at bins 16 and 64")
for i in [0, 16, 64, 192, 240]:
    mag = np.abs(fft_2tone[i]) / expected_scale
    print(f"Bin {i:3d}: magnitude = {mag:12.1f}")

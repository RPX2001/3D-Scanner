import numpy as np
from scipy.signal import convolve2d
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

# Processing variables
max_distance = 20  # Upper limit -- raw scan value only scanning "air"
min_distance = 0   # Lower limit -- raw scan value error: reporting negative reading
mid_thresh_upper = 0.5  # Offset radius threshold around 0
mid_thresh_lower = -mid_thresh_upper  # Offset radius threshold around 0
window_size = 3  # Window size for average filter to clean up mesh
interp_res = 1  # Interpolation resolution, i.e. keep every interRes-th row
center_distance = 10.3  # [cm] - Distance from scanner to center of turntable
z_delta = 0.1
raw_data = np.loadtxt('Data/data.txt')  # Load text file from SD Card
raw_data[raw_data < 0] = 0  # Remove erroneous scans from raw data
indices = np.where(raw_data == 9999)[0]  # Find indices of '9999' delimiter in text file, indicating end of z-height scan

# Arrange into matrix, where each row corresponds to one z-height
r = np.array([raw_data[indices[i - 1] + 1:indices[i]] for i in range(1, len(indices))])
r = center_distance - r  # Offset scan so that distance is with respect to turntable center of rotation
r[np.isnan(r)] = 0  # Replace NaN values with 0

# Remove scan values greater than maxDistance and less than minDistance
r[r > max_distance] = np.nan
r[r < min_distance] = np.nan

# Remove scan values around 0
mid_thresh_idx = np.logical_and(r > mid_thresh_lower, r < mid_thresh_upper)
r[mid_thresh_idx] = np.nan

# Create theta matrix with the same size as r -- each column in r corresponds to specific orientation
theta = np.linspace(0, 2 * np.pi, r.shape[1])
theta = np.tile(theta, (r.shape[0], 1))

# Create z-height array where each row corresponds to one z-height
z = np.arange(0, r.shape[0] * z_delta, z_delta).reshape(-1, 1)
z = np.tile(z, (1, r.shape[1]))

# Convert polar coordinates to Cartesian coordinates
x, y = np.cos(theta) * r, np.sin(theta) * r

# Replace NaN values in x, y with nearest neighbor at the same height
for i in range(1, x.shape[0]):
    if np.all(np.isnan(x[i])):
        x = x[:i]
        y = y[:i]
        z = z[:i]
        break

    latest_value_idx = np.where(~np.isnan(x[i]))[0][0]
    latest_x, latest_y = x[i, latest_value_idx], y[i, latest_value_idx]
    for j in range(x.shape[1]):
        if not np.isnan(x[i, j]):
            latest_x, latest_y = x[i, j], y[i, j]
        else:
            x[i, j], y[i, j] = latest_x, latest_y

# Resample array based on desired mesh resolution
interp_idx = np.arange(0, x.shape[0], interp_res)
x_interp, y_interp, z_interp = x[interp_idx, :], y[interp_idx, :], z[interp_idx, :]

# Smooth data to eliminate more noise
h = np.ones((1, window_size)) / window_size  # Define average filter
x_interp = np.pad(x_interp, ((0, 0), (0, window_size - 1)), mode='symmetric')  # Add symmetric duplicate padding along rows
y_interp = np.pad(y_interp, ((0, 0), (0, window_size - 1)), mode='symmetric')  # Add symmetric duplicate padding along rows
x_interp = convolve2d(x_interp, h, mode='valid')  # Filter x
y_interp = convolve2d(y_interp, h, mode='valid')  # Filter y

# Plot point cloud as a mesh to verify that processing is correct
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x_interp, y_interp, z_interp, color='b', marker='.')
plt.show()

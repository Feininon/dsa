
import matplotlib.pyplot as plt

# Input data
sizes = [10, 15, 20, 25, 28]
times = [0.000000, 0.000000, 0.005000, 0.183000, 1.377000]
# Configure plot styling
plt.figure(figsize=(10, 6))

# Plot performance curves
plt.plot(sizes, times, linewidth=2 )

# Customization
plt.title('toh', fontsize=14, fontweight='bold')
plt.xlabel('Input Size (n)', fontsize=12)
plt.ylabel('Time (Seconds)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=11)

plt.tight_layout()
plt.show()
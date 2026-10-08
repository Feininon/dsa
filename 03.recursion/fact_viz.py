import matplotlib.pyplot as plt

# Input data
sizes = [10000, 500000, 700000, 1000000, 2000000]
times = [0.000000, 0.001000, 0.001000, 0.002000, 0.004000]
# Configure plot styling
plt.figure(figsize=(10, 6))

# Plot performance curves
plt.plot(sizes, times, linewidth=2 )

# Customization
plt.title('factorial', fontsize=14, fontweight='bold')
plt.xlabel('Input Size (n)', fontsize=12)
plt.ylabel('Time (Seconds)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=11)

plt.tight_layout()
plt.show()
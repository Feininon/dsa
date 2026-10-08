
import matplotlib.pyplot as plt

# Input data
sizes = [1000, 5000, 10000, 20000, 50000]
best_times = [0.000000, 0.000000, 0.000000, 0.000000, 0.000000]
worst_times = [0.002000, 0.004000, 0.003000, 0.005000, 0.005000]
avg_times = [0.003000, 0.005000, 0.006000, 0.006000, 0.006000]

# Configure plot styling
plt.figure(figsize=(10, 6))

# Plot performance curves
plt.plot(sizes, best_times, linewidth=2, )
plt.plot(sizes, avg_times,  linewidth=2,)
plt.plot(sizes, worst_times, linewidth=2)

# Customization
plt.title('binary search Execution Time Comparison', fontsize=14, fontweight='bold')
plt.xlabel('Input Size (n)', fontsize=12)
plt.ylabel('Time (Seconds)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=11)

plt.tight_layout()
plt.show()
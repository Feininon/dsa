import matplotlib.pyplot as plt

# Input data
sizes = [1000, 5000, 10000, 20000, 50000]
best_times = [0.000000, 0.000000, 0.000000, 0.000000, 0.000000]
worst_times = [0.001000, 0.024000, 0.072000, 0.273000, 1.696000]
avg_times = [0.000000, 0.009000, 0.034000, 0.135000, 0.867000]

plt.figure(figsize=(10, 6))

# Plot performance curves
plt.plot(sizes, best_times, linewidth=2 )
plt.plot(sizes, avg_times,  linewidth=2)
plt.plot(sizes, worst_times, linewidth=2)

# Customization
plt.title('Insertion Sort Execution Time Comparison', fontsize=14, fontweight='bold')
plt.xlabel('Input Size (n)', fontsize=12)
plt.ylabel('Time (Seconds)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=11)

plt.tight_layout()
plt.show()
import matplotlib.pyplot as plt

# Input data
sizes = [100, 1000, 2500, 5000, 10000, 20000]
best_times= [0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.001000]
worst_times =  [0.000000, 0.001000, 0.010000, 0.032000,0.122000,  0.500000]
avg_times = [0.000000, 0.001000, 0.001000, 0.001000,0.001000,  0.002000]

plt.figure(figsize=(10, 6))

# Plot performance curves
plt.plot(sizes, best_times,marker='o', linewidth=2, label = 'best' )
plt.plot(sizes, avg_times, marker='s', linewidth=2, label = 'avg')
plt.plot(sizes, worst_times,marker='^', linewidth=2, label='worst')

# Customization
plt.title('Insertion Sort Execution Time Comparison', fontsize=14, fontweight='bold')
plt.xlabel('Input Size (n)', fontsize=12)
plt.ylabel('Time (Seconds)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=11)

plt.tight_layout()
plt.show()
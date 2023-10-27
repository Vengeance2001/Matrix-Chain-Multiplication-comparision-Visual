import matplotlib.pyplot as plt

# Read the execution times from the file
with open('execution_times.txt', 'r') as file:
    lines = file.readlines()
    execution_time_with_dp = float(lines[0].split(': ')[1])
    execution_time_without_dp = float(lines[1].split(': ')[1])

# Plot the execution times
algorithms = ['With DP', 'Without DP']
execution_times = [execution_time_with_dp, execution_time_without_dp]

plt.bar(algorithms, execution_times)
plt.xlabel('Algorithm')
plt.ylabel('Execution Time (ms)')
plt.title('Execution Time for Algorithms')
plt.show()

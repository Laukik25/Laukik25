# Shortest Job First (SJF) Scheduling Simulation in Python

# Predefined processes: pid, arrival_time, burst_time
processes = [
    {'pid': 1, 'at': 0, 'bt': 5},
    {'pid': 2, 'at': 1, 'bt': 3},
    {'pid': 3, 'at': 2, 'bt': 8},
    {'pid': 4, 'at': 3, 'bt': 6}
]

n = len(processes)
avg_tat = 0
avg_wt = 0

# Sort processes by burst time (SJF)
processes.sort(key=lambda x: x['bt'])

# Calculate Completion Time (CT)
current_time = 0
for proc in processes:
    if proc['at'] > current_time:
        current_time = proc['at']
    current_time += proc['bt']
    proc['ct'] = current_time

# Calculate Turnaround Time (TAT) and Waiting Time (WT)
for proc in processes:
    proc['tat'] = proc['ct'] - proc['at']
    proc['wt'] = proc['tat'] - proc['bt']
    avg_tat += proc['tat']
    avg_wt += proc['wt']

# Display table
print("\n==============================================")
print("Process\tAT\tBT\tCT\tTAT\tWT")
print("==============================================")
for proc in processes:
    print(f"P{proc['pid']}\t{proc['at']}\t{proc['bt']}\t{proc['ct']}\t{proc['tat']}\t{proc['wt']}")
print("==============================================")
print(f"Average Turnaround Time: {avg_tat / n:.2f}")
print(f"Average Waiting Time:    {avg_wt / n:.2f}")

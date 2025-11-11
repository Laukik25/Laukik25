# Priority Scheduling Simulation in Python (Non-preemptive)

# Predefined processes: id, burst_time, arrival_time, priority
processes = [
    {'id': 1, 'burst': 5, 'arrival': 0, 'priority': 2},
    {'id': 2, 'burst': 3, 'arrival': 1, 'priority': 1},
    {'id': 3, 'burst': 8, 'arrival': 2, 'priority': 4},
    {'id': 4, 'burst': 6, 'arrival': 3, 'priority': 3}
]

n = len(processes)
completed = [False] * n
completed_count = 0
time = 0
total_wt = 0
total_tat = 0

# Sort processes by arrival time first
processes.sort(key=lambda x: x['arrival'])

print("\n===== Priority Scheduling Simulation =====\n")

while completed_count < n:
    idx = -1
    highest_priority = float('inf')

    for i in range(n):
        if not completed[i] and processes[i]['arrival'] <= time:
            if processes[i]['priority'] < highest_priority:
                highest_priority = processes[i]['priority']
                idx = i

    if idx != -1:
        proc = processes[idx]
        time += proc['burst']
        proc['completion'] = time
        proc['turnaround'] = proc['completion'] - proc['arrival']
        proc['waiting'] = proc['turnaround'] - proc['burst']

        total_wt += proc['waiting']
        total_tat += proc['turnaround']
        completed[idx] = True
        completed_count += 1
    else:
        time += 1  # CPU idle

# Display table
print("==============================================")
print("PID\tAT\tBT\tPR\tCT\tTAT\tWT")
print("==============================================")
for proc in processes:
    print(f"{proc['id']}\t{proc['arrival']}\t{proc['burst']}\t{proc['priority']}\t"
          f"{proc['completion']}\t{proc['turnaround']}\t{proc['waiting']}")
print("==============================================")
print(f"Average Turnaround Time: {total_tat / n:.2f}")
print(f"Average Waiting Time:    {total_wt / n:.2f}")

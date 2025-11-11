from collections import deque

# Predefined processes: (id, arrival_time, burst_time)
processes = [
    {'id': 1, 'arrival': 0, 'burst': 5, 'remaining': 5},
    {'id': 2, 'arrival': 1, 'burst': 3, 'remaining': 3},
    {'id': 3, 'arrival': 2, 'burst': 8, 'remaining': 8},
    {'id': 4, 'arrival': 3, 'burst': 6, 'remaining': 6},
]

n = len(processes)
tq = 3  # Time Quantum

# Sort processes by arrival time
processes.sort(key=lambda x: x['arrival'])

current_time = 0
completed = 0
total_wt = 0
total_tat = 0
queue = deque()
mark = [0] * n

# Start with first process
queue.append(0)
mark[0] = 1

while completed < n:
    if not queue:
        # If queue is empty, add next unprocessed process
        for i in range(n):
            if processes[i]['remaining'] > 0:
                queue.append(i)
                mark[i] = 1
                break

    idx = queue.popleft()
    proc = processes[idx]

    # Start time for first execution
    if 'start' not in proc:
        proc['start'] = max(current_time, proc['arrival'])

    # CPU idle till process arrives
    current_time = max(current_time, proc['arrival'])

    if proc['remaining'] > tq:
        proc['remaining'] -= tq
        current_time += tq
    else:
        current_time += proc['remaining']
        proc['remaining'] = 0
        proc['completion'] = current_time
        proc['turnaround'] = proc['completion'] - proc['arrival']
        proc['waiting'] = proc['turnaround'] - proc['burst']
        total_wt += proc['waiting']
        total_tat += proc['turnaround']
        completed += 1

    # Add newly arrived processes
    for i in range(n):
        if not mark[i] and processes[i]['arrival'] <= current_time and processes[i]['remaining'] > 0:
            queue.append(i)
            mark[i] = 1

    # Reinsert the current process if not completed
    if proc['remaining'] > 0:
        queue.append(idx)

# Display table
print("\n===== Round Robin Scheduling Simulation =====\n")
print("==============================================")
print("PID\tAT\tBT\tCT\tTAT\tWT")
print("==============================================")
for proc in processes:
    print(f"P{proc['id']}\t{proc['arrival']}\t{proc['burst']}\t{proc['completion']}\t{proc['turnaround']}\t{proc['waiting']}")
print("==============================================")
print(f"Average Turnaround Time: {total_tat / n:.2f}")
print(f"Average Waiting Time:    {total_wt / n:.2f}")

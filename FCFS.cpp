# FCFS Scheduling Simulation in Python

# Predefined Arrival Time and Burst Time
at = [0, 1, 2, 3]
bt = [5, 3, 8, 6]
n = len(at)

# Initialize Completion Time, Turnaround Time, Waiting Time
ct = [0] * n
tat = [0] * n
wt = [0] * n
avg_tat = 0
avg_wt = 0

# Sort according to Arrival Time (FCFS)
processes = sorted(zip(at, bt), key=lambda x: x[0])
at = [p[0] for p in processes]
bt = [p[1] for p in processes]

# Calculate Completion Time (CT)
ct[0] = at[0] + bt[0]
for i in range(1, n):
    if at[i] > ct[i - 1]:
        ct[i] = at[i] + bt[i]
    else:
        ct[i] = ct[i - 1] + bt[i]

# Calculate Turnaround Time (TAT) and Waiting Time (WT)
for i in range(n):
    tat[i] = ct[i] - at[i]
    wt[i] = tat[i] - bt[i]
    avg_tat += tat[i]
    avg_wt += wt[i]

# Display Table
print("\n==============================================")
print("Process\tAT\tBT\tCT\tTAT\tWT")
print("==============================================")
for i in range(n):
    print(f"P{i+1}\t{at[i]}\t{bt[i]}\t{ct[i]}\t{tat[i]}\t{wt[i]}")
print("==============================================")
print(f"Average Turnaround Time: {avg_tat / n:.2f}")
print(f"Average Waiting Time:    {avg_wt / n:.2f}")

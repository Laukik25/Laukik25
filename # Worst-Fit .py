# Worst-Fit Memory Allocation Simulation in Python

# Predefined memory blocks and process sizes
memory_blocks = [100, 500, 200, 300, 600]   # Sizes of memory blocks
processes = [212, 417, 112, 426]            # Sizes of processes

n_blocks = len(memory_blocks)
n_processes = len(processes)

# Allocation list (-1 means not allocated)
allocation = [-1] * n_processes

# Worst-Fit Allocation
for i in range(n_processes):
    # Find the index of the largest block that can fit the process
    worst_idx = -1
    max_size = -1
    for j in range(n_blocks):
        if memory_blocks[j] >= processes[i] and memory_blocks[j] > max_size:
            max_size = memory_blocks[j]
            worst_idx = j
    if worst_idx != -1:
        allocation[i] = worst_idx
        memory_blocks[worst_idx] -= processes[i]  # Reduce block size by allocated process

# Display allocation table
print("\n==============================================")
print("Process\tSize\tBlock Allocated\tFragmentation")
print("==============================================")
for i in range(n_processes):
    print(f"P{i+1}\t{processes[i]}\t", end='')
    if allocation[i] != -1:
        frag = memory_blocks[allocation[i]]
        print(f"{allocation[i]+1}\t\t{frag}")
    else:
        print("Not Allocated\t-")
print("==============================================")

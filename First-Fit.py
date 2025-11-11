# First-Fit Memory Allocation Simulation in Python

# Predefined memory blocks and process sizes
memory_blocks = [100, 500, 200, 300, 600]   # Sizes of memory blocks
processes = [212, 417, 112, 426]            # Sizes of processes

# Number of blocks and processes
n_blocks = len(memory_blocks)
n_processes = len(processes)

# Allocation list (-1 means not allocated)
allocation = [-1] * n_processes

# First-Fit Allocation
for i in range(n_processes):
    for j in range(n_blocks):
        if memory_blocks[j] >= processes[i]:
            allocation[i] = j
            memory_blocks[j] -= processes[i]  # Reduce block size by allocated process
            break

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

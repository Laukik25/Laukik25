# Best Fit Memory Allocation Simulation in Python

# Predefined memory blocks and process sizes (you can change these)
memory_blocks = [100, 500, 200, 300, 600]   # Sizes of memory blocks
processes = [212, 417, 112, 426]            # Sizes of processes

# Number of blocks and processes
n = len(memory_blocks)
m = len(processes)

# Allocation list (-1 means not allocated)
allocation = [-1] * m
block_allocated = [-1] * n  # Tracks which block is occupied

# Best Fit Allocation
for i in range(m):
    best_idx = -1
    for j in range(n):
        if block_allocated[j] == -1 and memory_blocks[j] >= processes[i]:
            if best_idx == -1 or memory_blocks[j] < memory_blocks[best_idx]:
                best_idx = j
    if best_idx != -1:
        allocation[i] = best_idx
        block_allocated[best_idx] = i

# Display allocation table
print("\n==============================================")
print("Process\tSize\tBlock Allocated\tFragmentation")
print("==============================================")
for i in range(m):
    print(f"P{i+1}\t{processes[i]}\t", end='')
    if allocation[i] != -1:
        frag = memory_blocks[allocation[i]] - processes[i]
        print(f"{allocation[i]+1}\t\t{frag}")
    else:
        print("Not Allocated\t-")
print("==============================================")

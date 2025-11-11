# Next-Fit Memory Allocation Simulation in Python

# Predefined memory blocks and process sizes
memory_blocks = [120, 500, 250, 350, 600]   # Sizes of memory blocks (changed)
processes = [212, 417, 112, 426]            # Sizes of processes

n_blocks = len(memory_blocks)
n_processes = len(processes)

# Allocation list (-1 means not allocated)
allocation = [-1] * n_processes

# Next-Fit Allocation
last_allocated_index = 0  # Start from first block

for i in range(n_processes):
    count = 0
    j = last_allocated_index
    allocated = False
    while count < n_blocks:
        if memory_blocks[j] >= processes[i]:
            allocation[i] = j
            memory_blocks[j] -= processes[i]
            last_allocated_index = j  # Next search starts from this block
            allocated = True
            break
        j = (j + 1) % n_blocks
        count += 1
    if not allocated:
        allocation[i] = -1  # Process not allocated

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

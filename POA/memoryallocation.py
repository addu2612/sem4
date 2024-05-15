def bestfit(memory, processes):
    alloc_memory = {}  # Dictionary to store memory allocation
    for proc in processes:
        min_diff = float('inf')
        min_mem = 0
        for mem in memory:
            if mem - proc < min_diff and mem - proc >= 0:
                min_diff = mem - proc
                min_mem = mem
        if min_mem != 0:
            memory.remove(min_mem)
            alloc_memory[proc] = min_mem  # Store the allocation
            print(f"Process {proc} goes in memory {min_mem}")
        else:
            print(f"Process {proc} cannot be allocated.")
    return alloc_memory  # Return the allocation dictionary

def worstfit(memory, processes):
    memory.sort(reverse=True)
    alloc_memory = {}  # Dictionary to store memory allocation
    for proc in processes:
        allocated = False
        for i, mem in enumerate(memory):
            if mem >= proc:
                alloc_memory[proc] = mem  # Store the allocation
                print(f"Process {proc} goes in memory {mem}")
                memory[i] -= proc  # Update memory after allocation
                allocated = True
                break
        if not allocated:
            print(f"Process {proc} cannot be allocated.")
    return alloc_memory

def firstfit(memory, processes):
    alloc_memory = {}  # Dictionary to store memory allocation
    for proc in processes:
        allocated = False
        for i, mem in enumerate(memory):
            if mem >= proc:
                memory[i] -= proc
                alloc_memory[proc] = mem  # Store the allocation
                print(f"Process {proc} goes in memory {mem}")
                allocated = True
                break
        if not allocated:
            print(f"Process {proc} cannot be allocated.")
    return alloc_memory  # Return the allocation dictionary

def calculate_memory_utilization(memory, alloc_memory):
    total_allocated_memory = sum(alloc_memory.values())
    total_memory_after_allocation = sum(memory)
    total_memory_before_allocation = total_allocated_memory + total_memory_after_allocation

    if total_memory_before_allocation == 0:
        return 0.0

    return (total_allocated_memory / total_memory_before_allocation) * 100

# Example usage:
memory = [100, 500, 200, 300, 600]
processes = [212, 417, 112, 426]

best_fit_allocation = bestfit(memory.copy(), processes.copy())
print("\n")
worst_fit_allocation = worstfit(memory.copy(), processes.copy())
print("\n")
first_fit_allocation = firstfit(memory.copy(), processes.copy())

print("Best Fit Allocation:", best_fit_allocation)
print("\n")
print("Worst Fit Allocation:", worst_fit_allocation)
print("\n")
print("First Fit Allocation:", first_fit_allocation)

memory_utilization_best_fit = calculate_memory_utilization(memory, best_fit_allocation)
memory_utilization_worst_fit = calculate_memory_utilization(memory, worst_fit_allocation)
memory_utilization_first_fit = calculate_memory_utilization(memory, first_fit_allocation)

print("Memory Utilization - Best Fit:", memory_utilization_best_fit, "%")
print("Memory Utilization - Worst Fit:", memory_utilization_worst_fit, "%")
print("Memory Utilization - First Fit:", memory_utilization_first_fit, "%")

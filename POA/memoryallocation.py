def bestfit():
    memory = [100,500,200,300,600]
    processes = [100, 100, 500, 200]
    alloc_memory = {}  # Dictionary to store memory allocation
    for proc in processes:
        min_diff = float('inf')
        min_mem = 0
        for mem in memory:
            if mem - proc < min_diff and mem - proc >= 0:
                min_diff = mem - proc
                min_mem = mem
        memory.remove(min_mem)
        alloc_memory[proc] = min_mem  # Store the allocation
        print(f"Process {proc} goes in memory {min_mem}")
    return alloc_memory  # Return the allocation dictionary

def worstfit():
    memory = [200, 400, 600, 500, 300, 250]
    processes = [357, 210, 468, 491]
    memory.sort(reverse=True)
    alloc_memory = {}  # Dictionary to store memory allocation
    for proc in processes:
        if memory[0] - proc >= 0:
            alloc_memory[proc] = memory[0]  # Store the allocation
            print(f"Process {proc} goes in memory {memory[0]}")
            memory.remove(memory[0])
    return alloc_memory  # Return the allocation dictionary

def firstfit():
    memory = [200, 400, 600, 500, 300, 250]
    processes = [357, 210, 468, 491]
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
    total_memory = sum(memory)
    return (total_allocated_memory / total_memory) * 100

# Example usage:
memory = [200, 400, 600, 500, 300, 250]
best_fit_allocation = bestfit()
worst_fit_allocation = worstfit()
first_fit_allocation = firstfit()

print("Best Fit Allocation:", best_fit_allocation)
print("Worst Fit Allocation:", worst_fit_allocation)
print("First Fit Allocation:", first_fit_allocation)

memory_utilization_best_fit = calculate_memory_utilization(memory, best_fit_allocation)
memory_utilization_worst_fit = calculate_memory_utilization(memory, worst_fit_allocation)
memory_utilization_first_fit = calculate_memory_utilization(memory, first_fit_allocation)

print("Memory Utilization - Best Fit:", memory_utilization_best_fit, "%")
print("Memory Utilization - Worst Fit:", memory_utilization_worst_fit, "%")
print("Memory Utilization - First Fit:", memory_utilization_first_fit, "%")

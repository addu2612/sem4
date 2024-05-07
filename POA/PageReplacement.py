size = 3
pages = [2,3,2,1,5,2,4,5,3,2,5]

def fifo():
    hits, faults = 0, 0
    frame = []
    for p in pages:
        if p in frame:
            hits += 1
        elif len(frame) < 3:
            frame.append(p)
            faults += 1
        else:
            frame.pop(0)
            frame.append(p)
            faults += 1
    return hits, faults

def lru():
    hits, faults = 0, 0
    frame = []
    for p in pages:
        if len(frame)<3:
            frame.append(p)
            faults += 1
        else:
            if p in frame:
                hits += 1
                frame.remove(p)
                frame.append(p)
            else:
                frame.pop(0)
                frame.append(p)
                faults += 1
    return hits,faults 

def opt():
    hits, faults = 0, 0
    frame = []
    for p in pages:
        if p in frame:
            hits += 1
        elif len(frame) < 3:
            frame.append(p)
            faults += 1
        else:
            farthest_index = max((pages.index(page), i) for i, page in enumerate(frame))[1]
            frame[farthest_index] = p
            faults += 1
    return hits, faults

hits, faults = fifo()
print("FIFO")
print(f"Number of hits: {hits}")
print(f"Percentage hits:{(hits/len(pages))*100}")
print(f"Number of faults: {faults}") 
print(f"Percentage faults:{(faults/len(pages))*100}")

hits, faults = lru()
print("LRU")
print(f"Number of hits: {hits}")
print(f"Percentage hits:{(hits/len(pages))*100}")
print(f"Number of faults: {faults}") 
print(f"Percentage faults:{(faults/len(pages))*100}")

hits, faults = opt()
print("Optimal")
print(f"Number of hits: {hits}")
print(f"Percentage hits:{(hits/len(pages))*100}")
print(f"Number of faults: {faults}") 
print(f"Percentage faults:{(faults/len(pages))*100}")

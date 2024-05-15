def fifo(pages,frames):
    hits,faults=0,0
    index=0
    for i in range(len(pages)):
        flag=1
        for j in range(len(frames)):
            if (frames[j]==pages[i]):
                hits+=1
                flag=0
                break
        if flag:
            faults+=1
            frames[index]=pages[i]
            index=(index+1)%len(frames)
        print(frames)
    return hits,faults

def lru(pages,frames):
    hits,faults=0,0
    recent=[-1]*len(frames)

    for i in range(len(pages)):
        flag=1
        for j in range(len(frames)):
            if (frames[j]==pages[i]):
                hits+=1
                flag=0
                recent[j]=i
                break
        if flag:
            faults+=1
            index=recent.index(min(recent))
            frames[index]=pages[i]
            recent[index]=i
        print(frames)
    return hits,faults

def find_optimal(pages,frames,index):
    farthest=-1
    farthest_index=-1
    for i in range(len(frames)):
        try:
            cur_farthest=pages[index+1:].index(frames[i])
            if cur_farthest>farthest:
                farthest=cur_farthest
                farthest_index=i
        except ValueError:
            return i
    return farthest_index

def optimal(pages,frames):
    hits,faults=0,0
    for i in range(len(pages)):
        flag=1
        for j in range(len(frames)):
            if(frames[j]==pages[i]):
                flag=0
                hits+=1
                break
        if flag:
            faults+=1
            if -1 in frames:
                frames[frames.index(-1)]=pages[i]
            else:
                index=find_optimal(pages,frames,i)
                frames[index]=pages[i]
        print(frames)
    return hits,faults


frames=[]
pages=[]
n=int(input("Enter number of frames"))
for i in range(n):
        frames.append(-1)
p=int(input("Enter number of pages"))
for i in range(p):
    pages.append(int(input("Enter page:")))

hits, faults = fifo(pages.copy(),frames.copy())
print("FIFO")
print(f"Number of hits: {hits}")
print(f"Percentage hits:{(hits/len(pages))*100}")
print(f"Number of faults: {faults}") 
print(f"Percentage faults:{(faults/len(pages))*100}")

hits, faults = lru(pages.copy(),frames.copy())
print("LRU")
print(f"Number of hits: {hits}")
print(f"Percentage hits:{(hits/len(pages))*100}")
print(f"Number of faults: {faults}") 
print(f"Percentage faults:{(faults/len(pages))*100}")

hits, faults = optimal(pages.copy(),frames.copy())
print("Optimal")
print(f"Number of hits: {hits}")
print(f"Percentage hits:{(hits/len(pages))*100}")
print(f"Number of faults: {faults}") 
print(f"Percentage faults:{(faults/len(pages))*100}")

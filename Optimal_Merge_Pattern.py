import heapq

files = [5, 3, 2, 7, 9, 13]

heap_files = list(files)
heapq.heapify(heap_files)
total_operation=0
while(len(heap_files)>1):
    fileA = heapq.heappop(heap_files)
    fileB= heapq.heappop(heap_files)
    fileC = fileA+fileB
    total_operation=total_operation+fileC
    heapq.heappush(heap_files,fileC)
print(total_operation)
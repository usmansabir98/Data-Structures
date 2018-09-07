def partition(A, start, end):
    pivot = A[end]
    pIndex = start

    for i in range(start,end):
        if A[i] <= pivot:
            temp = A[pIndex]
            A[pIndex] = A[i]
            A[i] =temp
            pIndex+=1

    temp = A[pIndex]
    A[pIndex] = A[end]
    A[end] = temp
    return pIndex

def quicksort(A, start, end):
    if start < end:
        pIndex = partition(A,start,end)
        return quicksort(A, start, pIndex-1)
        return quicksort(A, pIndex+1, end)

A = [7,13,2,4,5,9,11]
quicksort(A, 0, len(A)-1)
print(A)
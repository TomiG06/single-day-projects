#Binary Search
def binarySearch(l, n):
    low = 0
    high = len(l)-1
    while low<=high:
        mid = (high+low)//2
        if l[mid] == n:
            return mid
        elif l[mid] < n:
            low = mid+1
        else:
            high = mid-1
    return -1

#Linear Search
def linearSearch(l, n):
    return [i for i, v in enumerate(l) if v == n][0]
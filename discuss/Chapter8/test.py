from random import *
import time

def InsertionSearch(a, n, k):
    low, high = 0, n - 1
    cnt = 0
    while low <= high:
        if k < a[low] or k > a[high]:
            return cnt
        if a[low] == a[high]:
            return cnt
        mid = low + 1 + (k - a[low]) * (high - low - 1) // (a[high] - a[low])  
        cnt += 1
        if a[mid] == k:
            return cnt
        elif a[mid] > k:
            high = mid - 1
        elif a[mid] < k:
            low = mid + 1
    return cnt

def BinarySearch(a, n, k):
    low, high = 0, n - 1
    cnt = 0
    while low <= high:
        mid = low + high >> 1
        cnt += 1
        if a[mid] == k:
            return cnt
        elif a[mid] > k:
            high = mid - 1
        elif  a[mid] < k:
            low = mid + 1
    return cnt

def main():
    T = 100
    n = 1000
    bsum, isum = 0, 0
    a = [0] * n
    for k in range(T):
        for i in range(n):
            a[i] = randint(1, 10000)
        a.sort()
        isum += InsertionSearch(a, n, randint(1, 10000))
        bsum += BinarySearch(a, n, randint(1, 10000))
    print('Insertion Search : {}'.format(isum / T))
    print('Binary Search : {}'.format(bsum / T))
    
if __name__ == '__main__':
    
    main()
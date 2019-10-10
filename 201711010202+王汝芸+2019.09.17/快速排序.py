'''
快速排序
'''

import numpy as np
import time
from heapq import heappush, heappop

a = np.random.randint(60000000,size=60000000).tolist()
print("快速排序")
print("size = 60,000,000")
time_start=time.time()

def Partition(arr,low,high):
    i = (low - 1)  # 最小元素索引
    pivot = arr[high]

    for j in range(low, high):

        # 当前元素小于或等于 pivot
        if arr[j] <= pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)

def QuickSort(a,low,high):
    if high > low:
        k = Partition(a,low,high)
        QuickSort(a,low,k-1)
        QuickSort(a,k+1,high)

QuickSort(a,0,len(a)-1)
time_end=time.time()
print('totally cost',time_end-time_start)
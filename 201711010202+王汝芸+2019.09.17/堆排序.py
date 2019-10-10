'''
¶ÑÅÅÐò
'''

import numpy as np
from heapq import heappush, heappop

a = np.random.randint(10,size=10).tolist()
print(a)

# ½¨¶Ñ
def MaxHeapify(a):
    heap = []
    for item in a:
        heappush(heap,item)
    heap.sort(reverse=True)  # ½µÐò
    return heap

def SiftDown(H,i):
    i += 1
    done = False
    if 2*i>len(H):
        return H
    while True:
        i = 2*i
        if i+1<=len(H) and H[i+1]>H[i]:
            i = i+1
        if H[int(i/2)]<H[i]:
            H[i],H[int(i/2)] = H[int(i/2)],H[i]
        else:
            done = True
        if 2*i>len(H) or done:
            return H


def HeapSort(a):
    a = MaxHeapify(a)
    for i in range(len(a)-1,-1,-1):
        a[0],a[i] = a[i],a[0]
        SiftDown(([0]+a[0:]),0)
    a = [a[-1]]+a[0:-1]
    return a

a = HeapSort(a)
print(a)




'''
πÈ≤¢≈≈–Ú
'''

import numpy as np

a = np.random.randint(10,size=10).tolist()
print(a)

def MergeSort(a):
    if len(a)<=1:
        return a
    middle = int(len(a)/2)
    left = MergeSort(a[:middle])
    right = MergeSort(a[middle:])
    return Merge(left,right)

def Merge(left,right):
    c = []
    h = j = 0
    while j < len(left) and h < len(right):
        if left[j] < right[h]:
            c.append(left[j])
            j += 1
        else:
            c.append(right[h])
            h += 1
    if j==len(left):
        c += right[h:]
    else:
        c += left[j:]
    return c

a = MergeSort(a)
print(a)
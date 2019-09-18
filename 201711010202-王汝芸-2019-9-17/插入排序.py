'''
插入排序
'''

import numpy as np

a = np.random.randint(10,size=10).tolist()
print(a)

for i in range(1, len(a)):
    key = a[i]
    j = i - 1
    while j >= 0 and key < a[j]:
        a[j + 1] = a[j]
        j -= 1
    a[j + 1] = key

print(a)
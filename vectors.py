import time
import numpy as np
start_time = time.time()

print("Списки в цикле")
x = [10**20, 1223, 10**18, 10**15, 3, -10**12]
y = [10**20, 2, -10**22, 10**13, 2111, 10**16]
rez = 0
for i in range(len(x)):
    rez += x[i]*y[i]
print(rez)
print("--- %s seconds ---" % (time.time() - start_time))

print("Массивы numpy")
start_time = time.time()
a = np.array([10**20, 1223, 10**18, 10**15, 3, -10**12])
b = np.array([10**20, 2, -10**22, 10**13, 2111, 10**16])
c = np.dot(a, b)
print(c)
print("--- %s seconds ---" % (time.time() - start_time))

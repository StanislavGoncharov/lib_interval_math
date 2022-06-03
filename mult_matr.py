import time
import numpy as np

with open('mx1') as f:
    a = [list(map(int, row.split())) for row in f.readlines()]
with open('mx2') as f:
    b = [list(map(int, row.split())) for row in f.readlines()]
print ("Рассчёт numpy\n")
A = np.matrix(a)
B = np.matrix(b)
start_time = time.time()
C = A.dot(B)
print("--- %s seconds ---" % (time.time() - start_time))

with open('outfile','wb') as f:
    for line in C:
        np.savetxt(f, line, fmt='%5.1i')

print ("Рассчёт по циклу\n") 
n = 3
start_time = time.time()
res = [[0 for j in range(n)] for i in range(n)]
for k in range(n):
	for i in range(n):
		for j in range(n):
			res[i][j] += a[i][k] * b[k][j]
print(res)
print("--- %s seconds ---" % (time.time() - start_time))

from pathlib import Path
import numpy as np

base_path = Path(__file__).parent
matrix_path = (base_path / "matrix.txt").resolve()

A = np.loadtxt(matrix_path, delimiter=',')

r = int(len(A))
c = int(len(A[0]))

result = np.zeros((r,c))
result[0,0] = A[0,0]

for i in range(0, r):
    for j in range(0, c):
        if i==0:
            result[0][j] = result[0][j-1] + A[0][j]
        elif j==0:
            result[i][0] = result[i-1][0] + A[i][0]
        else:
            result[i][j] = min(result[i-1][j], result[i][j-1]) + A[i][j]

print(result)
print(result[r-1][c-1])

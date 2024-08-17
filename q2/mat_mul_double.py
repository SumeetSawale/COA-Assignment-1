from numpy import random
import time

n = 512

def mat_mul(mat) :
    out = [[0] * n for _ in range(n)]
    
    for i in range(n) :
        for j in range(n) :
            for k in range(n) :
                out[i][j] += mat[i][k] * mat[k][j]
    
    return out

def create_matrix() :
    return random.randn(n, n)

def main() :
    st = time.time()
    matrix = create_matrix()

    st2 = time.time()
    mat_mul(matrix)
    end = time.time()

    print(f"Meat time for N = {n} is: {end - st2}")
    print(f"Total time for N = {n} is: {end - st}")

main()
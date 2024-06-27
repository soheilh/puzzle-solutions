from math import sqrt, floor
import os

os.system('cls' if os.name == 'nt' else 'clear')
number = 10**14

# def max_square_divisor_2(n):
#     ans = 1
#     temp = n
#     for i in range(int(sqrt(n)), 1, -1):
#         if (n % i**2 == 0):
#            return i**2
#     return 1

# def sum_of_divisor(n):
#     ans = 0
#     for i in range(1,n+1):
#         print(i, " => " , max_square_divisor_2(i))
#         ans += max_square_divisor_2(i)
#     return ans

# print(sum_of_divisor(number))

def sum_of_divisor(n):
    sqrt_n = int(sqrt(n))
    s = [0] + [1]*sqrt_n
    for i in range(sqrt_n,0,-1):
        print(i)
        s[i] = floor(n/i**2) - sum(s[i*j] for j in range(floor(sqrt_n/i),1,-1))
    return sum(s[i]*i*i for i in range(len(s))) // 1000000007

print(sum_of_divisor(number))
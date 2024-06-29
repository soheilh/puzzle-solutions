"""
+------------------------------------------------------------------------------+
| Number       : 12                                                            |
| Title        : Highly Divisible Triangular Number                            |
| Link         : https://projecteuler.net/problem=12                           |
| Description  : The value of the first triangle number to have over five      |
                 hundred divisors.                                             |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-06-30                                                    |
| Last Modified: 2024-06-30                                                    |
+------------------------------------------------------------------------------+
"""
from math import isqrt
import os

def kth_triangular(n):
    return n * (n + 1) // 2

def get_divisors_count(n):
    count = 0
    root = isqrt(n)
    for i in range(1, root + 1):
        if n % i == 0:
            count += 2  # i and n//i
    if root * root == n:
        count -= 1  # if n is a perfect square
    return count

def divisible_triangular(min_divisors):
    i = 1
    while True:
        tnum = kth_triangular(i)
        if get_divisors_count(tnum) > min_divisors:
            return tnum
        i += 1

def main():
    os.system('cls' if os.name == 'nt' else 'clear')
    n = 500
    print(divisible_triangular(n))

if __name__ == "__main__":
    main()
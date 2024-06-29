"""
+------------------------------------------------------------------------------+
| Number       : 10                                                            |
| Title        : Summation of Primes                                           |
| Link         : https://projecteuler.net/problem=10                           |
| Description  : The sum of all the primes below two million..                 |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-06-29                                                    |
| Last Modified: 2024-06-29                                                    |
+------------------------------------------------------------------------------+
"""
from math import ceil, log, sqrt
import os

def sieve_of_eratosthenes(n):
    is_prime = [True] * (n+1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(sqrt(n))):
        if is_prime[i]:
            for j in range(i*i, n+1, i):
                is_prime[j] = False
    return [p for p in range(n+1) if is_prime[p]]

def main():
    os.system('cls' if os.name == 'nt' else 'clear')
    n = 2000000
    primes = sieve_of_eratosthenes(n)
    print(f"The sum of all primes below {n} is: {sum(primes)}")

if __name__ == "__main__":
    main()
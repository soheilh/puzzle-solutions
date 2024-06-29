"""
+------------------------------------------------------------------------------+
| Number       : 4                                                             |
| Title        : Largest Palindrome Product                                    |
| Link         : https://projecteuler.net/problem=4                            |
| Description  : The largest palindrome made from the product of two 3-digit   |
|                numbers.                                                      |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-06-29                                                    |
| Last Modified: 2024-06-29                                                    |
+------------------------------------------------------------------------------+
"""
import os

def is_palindrome(n):
    return str(n) == str(n)[::-1]

def largest_palindrome_product(n):
    max_palindrome = 0
    min = 10**(n-1)
    max = (10**n)
    for i in range(min, max):
        for j in range(min, max):
            product = i*j
            if is_palindrome(product) and product > max_palindrome:
                max_palindrome = product
    return max_palindrome

def main():
    os.system('cls' if os.name == 'nt' else 'clear')
    print("Enter you number: ")
    num = int(input())
    print(largest_palindrome_product(num))

if __name__ == "__main__":
    main()
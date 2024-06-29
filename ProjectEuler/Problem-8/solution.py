"""
+------------------------------------------------------------------------------+
| Number       : 8                                                             |
| Title        : Largest Product in a Series                                   |
| Link         : https://projecteuler.net/problem=8                            |
| Description  : Thirteen adjacent digits have largest prodect.                |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-06-29                                                    |
| Last Modified: 2024-06-29                                                    |
+------------------------------------------------------------------------------+
"""
from pathlib import Path
import os

def open_file(file_name):
    base_path = Path(__file__).parent
    file_path = (base_path / file_name).resolve()
    with open(file_path, 'r') as file:
        data = file.read().replace('\n', '')
    return data

def multiply_numbers(list):
    product = 1
    for c in list:
        product *= int(c)
    return product

def largest_product(n, file):
    numbers = open_file(file)
    i=0
    max_product = 1
    while i+n-1 <= len(numbers):
        product = multiply_numbers(numbers[i:i+n])
        if product > max_product:
            max_product = product
        i += 1
    return max_product

def main():
    os.system('cls' if os.name == 'nt' else 'clear')
    print(largest_product(13, "numbers.txt"))

if __name__ == "__main__":
    main()
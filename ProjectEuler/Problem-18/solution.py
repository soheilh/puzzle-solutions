"""
+------------------------------------------------------------------------------+
| Number       : 18                                                            |
| Title        : Maximum Path Sum I                                            |
| Link         : https://projecteuler.net/problem=18                           |
| Description  : The maximum total from top to bottom of the triangle          |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-06-30                                                    |
| Last Modified: 2024-06-30                                                    |
+------------------------------------------------------------------------------+
"""

from pathlib import Path

def read_tree(file_name):
    # Determine the path to the file
    base_path = Path(__file__).parent
    file_path = (base_path / file_name).resolve()
    
    # Read and process the file content
    with open(file_path, 'r') as file:
        lines = file.read().strip().split('\n')

    # Convert lines to a list of lists
    triangle = [list(map(int, line.split())) for line in lines]
    
    return triangle

def get_max_path(triangle):
    # Create a copy of the triangle to store the maximum path sums
    max_sums = [row[:] for row in triangle]
    
    # Start from the second-to-last row and move upwards to the top
    for i in range(len(max_sums) - 2, -1, -1):
        for j in range(len(max_sums[i])):
            max_sums[i][j] += max(max_sums[i + 1][j], max_sums[i + 1][j + 1])
    
    # The top element now contains the maximum path sum
    return max_sums[0][0]

def main():
    # Clear the console
    from os import system, name
    system('cls' if name == 'nt' else 'clear')

    # Read the triangle from the file
    triangle = read_tree("tree.txt")
    print("Triangle matrix:\n", triangle)
    
    # Compute the maximum path sum
    max_path_sum = get_max_path(triangle)
    print("Sum of maximum path:", max_path_sum)

if __name__ == "__main__":
    main()

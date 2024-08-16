"""
+------------------------------------------------------------------------------+
| Number       : 42                                                            |
| Title        : Trapping Rain Water                                           |
| Link         : https://leetcode.com/problems/trapping-rain-water             |
| Description  : Given n non-negative integers representing an elevation       |
|                map, compute how much water it can trap after raining.        |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-08-16                                                    |
| Last Modified: 2024-08-16                                                    |
+------------------------------------------------------------------------------+
"""

"""
- Time Complexity: O(n) - The algorithm iterates through the list only once.
- Space Complexity: O(1) - The algorithm uses a constant amount of extra space, regardless of the input list size.
"""

def trap(height: List[int]) -> int:
    left = 0
    right = len(height) - 1
    left_max, right_max = height[left], height[right]
    water = 0

    while left < right:
        if left_max < right_max:
            water += left_max - height[left]
            left += 1
            if height[left] > left_max:
                left_max = height[left]
        else:
            water += right_max - height[right]
            right -= 1
            if height[right] > right_max:
                right_max = height[right]
    return water

with open('user.out', 'w') as f:
    data = map(loads, stdin)
    for height in data:
        print(json.dumps(trap(height), separators=(',',':')), file=f)
exit()


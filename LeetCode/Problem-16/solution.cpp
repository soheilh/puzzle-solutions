/*
+--------------------------------------------------------------------------+
| Problem Number : 16                                                      |
| Title          : 3Sum Closest                                            |
| Link           : https://leetcode.com/problems/3sum-closest              |
| Description    : Given an integer array 'nums' of length 'n', find three |
|                  integers in 'nums' such that the sum is closest to a    |
|                  given target. Return the sum of the three integers.     |
+--------------------------------------------------------------------------+
| Author         : Soheil Hasani                                           |
| Date Created   : 2024-08-08                                              |
| Last Updated   : 2024-08-08                                              |
+--------------------------------------------------------------------------+
*/

/*
 * Time Complexity: O(n^2) - Sorting the array takes O(n log n) and the two-pointer search takes O(n^2) in the worst case.
 * Space Complexity: O(log n) - This is the space complexity for sorting.
*/

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    static int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end()); // Sort the input array
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[2]; // Initialize with the sum of the first three elements

        // Iterate through the array
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                // Update result if this sum is closer to the target
                if (std::abs(target - total) < std::abs(target - result)) {
                    result = total;
                }

                // Move the pointers based on comparison with target
                if (total > target) {
                    right--;
                } else if (total < target) {
                    left++;
                } else {
                    return total; // Exact match found
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int closest_sum = sol.threeSumClosest(nums, target);
    std::cout << "The closest sum is: " << closest_sum << std::endl;
    return 0;
}

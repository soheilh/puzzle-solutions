/*
+--------------------------------------------------------------------------+
| Problem Number : 18                                                      |
| Title          : 4Sum                                                    |
| Link           : https://leetcode.com/problems/4sum                      |
| Description    : Given an integer array 'nums', return all unique        |
|                  quadruplets that sum to the target value.               |
+--------------------------------------------------------------------------+
| Author         : Soheil Hasani                                           |
| Date Created   : 2024-08-08                                              |
| Last Updated   : 2024-08-08                                              |
+--------------------------------------------------------------------------+
*/

/*
 - Time Complexity  : O(n^3) - Sorting takes O(n log n), finding quadruplets takes O(n^3).
 - Space Complexity : O(m) - Space for storing m quadruplets; auxiliary space is O(1).
*/


#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end()); // Sort the input array
        std::vector<std::vector<int>> quadruplets;
        int n = nums.size();

        if (n < 4) return quadruplets; // Early return if not enough elements

        // Iterate through the array
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicates

            // Early termination if the smallest possible sum is already too large
            if ((long long)nums[i] + (long long)nums[i + 1] + (long long)nums[i + 2] + (long long)nums[i + 3] > target)
                break;

            // Skip the current number if it, together with the three largest numbers, is still too small
            if ((long long)nums[i] + (long long)nums[n - 1] + (long long)nums[n - 2] + (long long)nums[n - 3] < target)
                continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // Skip duplicates

                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long total = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (total == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for left and right pointers
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        // Move the pointers after skipping duplicates
                        left++;
                        right--;
                    } else if (total < target) {
                        left++; // Move the left pointer to the right
                    } else {
                        right--; // Move the right pointer to the left
                    }
                }
            }
        }
        return quadruplets;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    std::vector<std::vector<int>> four_sum = sol.fourSum(nums, target);

    std::cout << "The quadruplets are: ";
    for (const std::vector<int>& quad : four_sum) {
        std::cout << '[';
        for (size_t i = 0; i < quad.size(); ++i) {
            std::cout << quad[i];
            if (i < quad.size() - 1) std::cout << ", ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    return 0;
}

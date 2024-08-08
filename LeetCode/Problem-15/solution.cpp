/*
+--------------------------------------------------------------------------+
| Problem Number : 15                                                      |
| Title          : 3Sum                                                    |
| Link           : https://leetcode.com/problems/3sum                      |
| Description    : Given an integer array 'nums', return all unique        |
|                  triplets that sum to zero.                              |
+--------------------------------------------------------------------------+
| Author         : Soheil Hasani                                           |
| Date Created   : 2024-08-08                                              |
| Last Updated   : 2024-08-08                                              |
+--------------------------------------------------------------------------+
*/

/*
 * Time Complexity: O(n^2) - Sorting the array takes O(n log n) and the two-pointer search takes O(n^2) in the worst case.
 * Space Complexity: O(k + log n) - Includes space for storing triplets and sorting.
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // Sort the input array
        std::vector<std::vector<int>> triplets;
        int n = nums.size();

        // Iterate through the array
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            if (nums[i] > 0) break; // If the current number is > 0, break, as no three positive numbers can sum to zero

            int left = i + 1, right = n - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total < 0) {
                    left++;
                } else if (total > 0) {
                    right--;
                } else {
                    triplets.push_back({nums[i], nums[left], nums[right]}); // Add the triplet to the result
                    while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                    while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                    left++;
                    right--;
                }
            }
        }

        return triplets;
    }
};

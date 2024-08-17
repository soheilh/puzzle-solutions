/*
+------------------------------------------------------------------------------+
| Number       : 4                                                             |
| Title        : Median of Two Sorted Arrays                                   |
| Link         : https://leetcode.com/problems/median-of-two-sorted-arrays     |
| Description  : Given two sorted arrays nums1 and nums2 of size m and n       |
|                respectively, return the median of the two sorted arrays.     |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-08-07                                                    |
| Last Modified: 2024-08-07                                                    |
+------------------------------------------------------------------------------+
*/

/*
 - Time Complexity: O(log(min(m,n))) - Recursively halves the search space, 
                                       where m and n are the sizes of the two input arrays.
 - Space Complexity: O(1) - Uses constant extra space.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        int k1 = (totalSize + 1) / 2;
        int k2 = (totalSize + 2) / 2;
        
        return (findKth(nums1, 0, nums2, 0, k1) + findKth(nums1, 0, nums2, 0, k2)) / 2.0;
    }
    
private:
    int findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
        if (start1 >= nums1.size()) return nums2[start2 + k - 1];
        if (start2 >= nums2.size()) return nums1[start1 + k - 1];
        
        if (k == 1) return min(nums1[start1], nums2[start2]);
        
        int mid1 = (start1 + k / 2 - 1 < nums1.size()) ? nums1[start1 + k / 2 - 1] : INT_MAX;
        int mid2 = (start2 + k / 2 - 1 < nums2.size()) ? nums2[start2 + k / 2 - 1] : INT_MAX;
        
        if (mid1 < mid2) {
            return findKth(nums1, start1 + k / 2, nums2, start2, k - k / 2);
        } else {
            return findKth(nums1, start1, nums2, start2 + k / 2, k - k / 2);
        }
    }
};

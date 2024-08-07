/*
+------------------------------------------------------------------------------+
| Number       : 9                                                             |
| Title        : Palindrome Number                                             |
| Link         : https://leetcode.com/problems/palindrome-number               |
| Description  : Check if an integer is a palindrome.                          |
+------------------------------------------------------------------------------+
| Created By   : Soheil Hasani                                                 |
| Created On   : 2024-08-06                                                    |
| Last Modified: 2024-08-06                                                    |
+------------------------------------------------------------------------------+
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long int reverse = 0;
        int temp = x;
        while (temp > 0) {
            reverse = (reverse * 10) + (temp % 10);
            temp /= 10;
        }

        return (x == reverse);
    }
};

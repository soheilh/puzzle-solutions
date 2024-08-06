using namespace std;

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

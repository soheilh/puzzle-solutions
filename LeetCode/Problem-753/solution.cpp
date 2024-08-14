/*
+--------------------------------------------------------------------------+
| Problem Number : 753                                                     |
| Title          : Cracking the safe                                       |
| Link           : https://leetcode.com/problems/cracking-the-safe         |
| Description    : Generate the smallest lexicographical sequence such     |
|                  that every possible combination of n digits of base k   |
|                  appears as a substring.                                 |
+--------------------------------------------------------------------------+
| Author         : Soheil Hasani                                           |
| Date Created   : 2024-08-13                                              |
| Last Updated   : 2024-08-13                                              |
+--------------------------------------------------------------------------+
*/

/*
 * Time Complexity: O(k^n) - Every possible combination of length n is visited.
 * Space Complexity: O(k^n) - Space used to store the sequence and recursion stack.
*/

using namespace std;
#include<string>
#include<vector>
#include<functional>

class Solution {
public:
    string crackSafe(int n, int k) {
        if (k == 1) return string(n, '0');        
        string alphabet;
        for (int i = 0; i < k; i++) alphabet += to_string(i);
        string sequence = de_bruijn(n, alphabet);
        sequence += sequence.substr(0, n-1);
        return sequence;
    }

private:
    string de_bruijn(int n, const string& alphabet) {
        int k = alphabet.size();
        vector<int> a(k * n, 0);
        string sequence;

        function<void(int, int)> db = [&](int t, int p) {
            if (t > n) {
                if (n % p == 0)
                    for (int i = 1; i <= p; i++) sequence += alphabet[a[i]];
            } else {
                a[t] = a[t - p];
                db(t + 1, p);
                for (int j = a[t - p] + 1; j < k; ++j) {
                    a[t] = j;
                    db(t + 1, t);
                }
            }
        };

        db(1, 1);
        return sequence;
    }
};


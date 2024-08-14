"""
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
"""

"""
 - Time Complexity: O(k^n) - Every possible combination of length n is visited.
 - Space Complexity: O(k^n) - Space used to store the sequence and recursion stack.
"""
class Solution:
    def crackSafe(self, n, k):
        if k == 1:
            return '0' * n
        
        alphabet = ''.join(str(i) for i in range(k))
        sequence = self.de_bruijn(n, alphabet)
        return sequence + sequence[:n-1]
    
    def de_bruijn(self, n, alphabet):
        k = len(alphabet)
        a = [0] * (k * n)
        sequence = []

        def db(t, p):
            if t > n:
                if n % p == 0:
                    sequence.extend(alphabet[a[i]] for i in range(1, p + 1))
            else:
                a[t] = a[t - p]
                db(t + 1, p)
                for j in range(a[t - p] + 1, k):
                    a[t] = j
                    db(t + 1, t)

        db(1, 1)
        return ''.join(sequence)


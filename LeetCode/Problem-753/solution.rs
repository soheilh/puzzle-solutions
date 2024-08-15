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
 - Time Complexity: O(k^n) - Every possible combination of length n is visited.
 - Space Complexity: O(k^n) - Space used to store the sequence and recursion stack.
*/

impl Solution {
    pub fn crack_safe(n: i32, k: i32) -> String {
        if k == 1 {
            return "0".repeat(n as usize);
        }
        
        let alphabet: Vec<char> = (0..k).map(|i| char::from_digit(i as u32, 10).unwrap()).collect();
        let sequence = Solution::de_bruijn(n as usize, &alphabet);
        return format!("{}{}", sequence, &sequence[..(n as usize - 1)]);
    }

    fn de_bruijn(n: usize, alphabet: &[char]) -> String {
        let k = alphabet.len();
        let mut a = vec![0; k * n];
        let mut sequence = String::new();
        
        fn db(t: usize, p: usize, n: usize, k: usize, a: &mut Vec<usize>, sequence: &mut String, alphabet: &[char]) {
            if t > n {
                if n % p == 0 {
                    for i in 1..=p {
                        sequence.push(alphabet[a[i]]);
                    }
                }
            } else {
                a[t] = a[t - p];
                db(t + 1, p, n, k, a, sequence, alphabet);
                for j in (a[t - p] + 1)..k {
                    a[t] = j;
                    db(t + 1, t, n, k, a, sequence, alphabet);
                }
            }
        }
        
        db(1, 1, n, k, &mut a, &mut sequence, alphabet);
        sequence
    }
}


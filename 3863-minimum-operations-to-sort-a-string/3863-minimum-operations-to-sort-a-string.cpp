#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // Case 1: Already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // Case 2: Length 2 cannot be sorted if not already sorted
        if (n == 2) {
            return -1;
        }
        
        // Find the first occurrence of the minimum character 
        // and the last occurrence of the maximum character
        int min_idx = 0, max_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] < s[min_idx]) {
                min_idx = i;
            }
            if (s[i] >= s[max_idx]) {
                max_idx = i;
            }
        }
        
        // Case 3: Min char is at the very beginning or max char is at the very end -> 1 op
        if (min_idx == 0 || max_idx == n - 1) {
            return 1;
        }
        
        // Case 4: Max char at the start and min char at the end -> 3 ops
        if (max_idx == 0 && min_idx == n - 1) {
            return 3;
        }
        
        // Case 5: Otherwise -> 2 ops
        return 2;
    }
};
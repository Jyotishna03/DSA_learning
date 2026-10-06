class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;
        int add_needed = 0;

        for (char c : s) {
            if (c == '(') {
                open_needed++;
            } else {
                if (open_needed > 0) {
                    open_needed--; // Match with an open '('
                } else {
                    add_needed++;  // Unmatched ')', need to insert a '('
                }
            }
        }

        return open_needed + add_needed;
    }
};
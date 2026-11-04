class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // If we need an odd number of ')' to close a previous group, 
                // we insert one ')' right here.
                if (open % 2 != 0) {
                    ans++;
                    open--; // consumed one requirement
                }
                open += 2; // Each '(' requires two ')'
            } else { // s[i] == ')'
                open--;
                // If open drops below 0, we have an extra ')' without an opening '('
                if (open < 0) {
                    ans++;     // Insert a '('
                    open += 2; // That inserted '(' now contributes 2 expected ')'
                }
            }
        }
        
        // Any remaining open parentheses need 2 closing parentheses each
        return ans + open;
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        
        solve("", 0, 0, n, ans);
        
        return ans;
    }
    
    void solve(string s, int open, int close, int n, vector<string>& ans) {
        
        // If we used n opening and n closing brackets
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }
        
        // Add '(' if we still have opening brackets
        if (open < n) {
            solve(s + "(", open + 1, close, n, ans);
        }
        
        // Add ')' only if closing brackets are less than opening
        if (close < open) {
            solve(s + ")", open, close + 1, n, ans);
        }
    }
};
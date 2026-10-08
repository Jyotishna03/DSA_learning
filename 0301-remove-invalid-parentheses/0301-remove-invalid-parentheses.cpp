#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remL = 0, remR = 0;
        
        // Count how many '(' and ')' need to be removed
        for (char c : s) {
            if (c == '(') {
                remL++;
            } else if (c == ')') {
                if (remL > 0) {
                    remL--;
                } else {
                    remR++;
                }
            }
        }
        
        unordered_set<string> resultSet;
        string current = "";
        backtrack(s, 0, 0, remL, remR, current, resultSet);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    void backtrack(const string& s, int index, int balance, int remL, int remR, string& current, unordered_set<string>& resultSet) {
        // Base case
        if (index == s.length()) {
            if (remL == 0 && remR == 0 && balance == 0) {
                resultSet.insert(current);
            }
            return;
        }

        // Prune invalid branches
        if (balance < 0 || remL < 0 || remR < 0) return;

        char ch = s[index];

        // 1. Option to REMOVE current character
        if (ch == '(' && remL > 0) {
            backtrack(s, index + 1, balance, remL - 1, remR, current, resultSet);
        } else if (ch == ')' && remR > 0) {
            backtrack(s, index + 1, balance, remL, remR - 1, current, resultSet);
        }

        // 2. Option to KEEP current character
        current.push_back(ch);
        int newBalance = balance + (ch == '(' ? 1 : (ch == ')' ? -1 : 0));
        backtrack(s, index + 1, newBalance, remL, remR, current, resultSet);
        current.pop_back(); // Backtrack
    }
};
class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }

            else if (ch == ')') {
                low--;
                high--;
            }

            else { // '*'
                low--;    // '*' can be ')'
                high++;   // '*' can be '('
            }

            // Too many ')'
            if (high < 0)
                return false;

            // Minimum open brackets can't be negative
            if (low < 0)
                low = 0;
        }

        return low == 0;
    }
};
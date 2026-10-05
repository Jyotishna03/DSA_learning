#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        std::stack<int> st;
        st.push(0); // Outer level score
        
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int v = st.top();
                st.pop();
                st.top() += std::max(2 * v, 1);
            }
        }
        
        return st.top();
    }
};
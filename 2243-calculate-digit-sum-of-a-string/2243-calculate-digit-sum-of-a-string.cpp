class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next_round = "";
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                // Sum the digits in the current group of size up to k
                for (int j = i; j < min((int)s.length(), i + k); ++j) {
                    sum += s[j] - '0';
                }
                next_round += to_string(sum);
            }
            s = next_round;
        }
        return s;
    }
};
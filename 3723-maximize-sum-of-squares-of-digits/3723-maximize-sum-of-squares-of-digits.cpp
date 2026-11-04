#include <string>
#include <algorithm>

class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        long maxPossibleSum = 9L * num;
        if (sum < 1 || sum > maxPossibleSum) {
            return "";
        }
        
        std::string result = "";
        int remainingSum = sum;
        int remainingDigits = num;
        
        for (int i = 0; i < num; i++) {
            remainingDigits--;
            for (int d = 9; d >= 0; d--) {
                if (i == 0 && d == 0 && num > 1) continue;
                if (remainingSum - d <= 9 * remainingDigits && remainingSum - d >= 0) {
                    result += std::to_string(d);
                    remainingSum -= d;
                    break;
                }
            }
        }
        return result;
    }
};
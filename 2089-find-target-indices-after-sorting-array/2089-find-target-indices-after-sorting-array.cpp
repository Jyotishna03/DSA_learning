#include <vector>

class Solution {
public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        int lessCount = 0;
        int targetCount = 0;
        
        // Count elements less than target and elements equal to target
        for (int num : nums) {
            if (num < target) {
                lessCount++;
            } else if (num == target) {
                targetCount++;
            }
        }
        
        // Construct the result vector
        std::vector<int> result;
        for (int i = 0; i < targetCount; i++) {
            result.push_back(lessCount + i);
        }
        
        return result;
    }
};
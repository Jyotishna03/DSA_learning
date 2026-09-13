class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Width is the distance between the two vertical lines
            int width = right - left;
            
            // Height of the container is limited by the shorter line
            int currentHeight = std::min(height[left], height[right]);
            
            // Calculate current area and update maximum water found so far
            int currentWater = width * currentHeight;
            maxWater = std::max(maxWater, currentWater);
            
            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
        
    }
};
import java.util.Arrays;

class Solution {
    
    // Helper function to calculate the digit sum of a number
    private int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;
        
        // Store elements as {number, digitSum, originalIndex}
        Integer[][] items = new Integer[n][3];
        for (int i = 0; i < n; i++) {
            items[i][0] = nums[i];
            items[i][1] = getDigitSum(nums[i]);
            items[i][2] = i;
        }
        
        // Sort based on digit sum, then by number value (tie-breaker)
        Arrays.sort(items, (a, b) -> {
            if (!a[1].equals(b[1])) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });
        
        // Find the minimum swaps using cycle detection
        boolean[] visited = new boolean[n];
        int cycles = 0;
        
        for (int i = 0; i < n; i++) {
            // If the element is already visited or already in the correct position
            if (visited[i] || items[i][2] == i) {
                continue;
            }
            
            // Traverse the cycle
            int curr = i;
            int cycleSize = 0;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = items[curr][2]; // Move to the target index
                cycleSize++;
            }
            
            if (cycleSize > 1) {
                cycles += (cycleSize - 1);
            }
        }
        
        return cycles;
    }
}
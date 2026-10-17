class Solution {
    public String maxSumOfSquares(int num, int sum) {
        
        long maxPossibleSum = 9L * num;
        if (sum < 1 || sum > maxPossibleSum) {
            return "";
        }
        
        StringBuilder sb = new StringBuilder();
        int remainingSum = sum;
        int remainingDigits = num;
        
        for (int i = 0; i < num; i++) {
            
            int minNeeded = Math.max(0, remainingSum - 9 * (remainingDigits - 1));
            int maxPossible = Math.min(9, remainingSum);
            
            
        }
        
        
        
        for (int i = 0; i < num; i++) {
            remainingDigits--;
            
            for (int d = 9; d >= 0; d--) {
                
                if (i == 0 && d == 0 && num > 1) continue; 
                
                if (remainingSum - d <= 9 * remainingDigits && remainingSum - d >= 0) {
                    sb.append(d);
                    remainingSum -= d;
                    break;
                }
            }
        }
        
        return sb.toString();
    }
}
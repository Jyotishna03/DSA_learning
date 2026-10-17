class Solution {
    public String maxSumOfSquares(int num, int sum) {
        // Check if the sum is within valid bounds
        long maxPossibleSum = 9L * num;
        if (sum < 1 || sum > maxPossibleSum) {
            return "";
        }
        
        StringBuilder sb = new StringBuilder();
        int remainingSum = sum;
        int remainingDigits = num;
        
        for (int i = 0; i < num; i++) {
            // We want the largest possible digit for the current position (from 9 down to 0)
            // But we must ensure the remaining sum can be formed by the remaining digits
            // and the maximum sum the remaining digits can form is 9 * (remainingDigits - 1)
            int minNeeded = Math.max(0, remainingSum - 9 * (remainingDigits - 1));
            int maxPossible = Math.min(9, remainingSum);
            
            // To maximize the number lexicographically, we pick the highest valid digit.
            // Wait, to maximize the score, we actually want larger digits *anywhere* because squares are symmetric?
            // Let's re-read: "maximize the score... If there are multiple possible integers, return the maximum one."
            // Since square sum (x^2 + y^2) is symmetric with respect to digit order, *any* permutation 
            // of the same multiset of digits gives the exact same score!
            // Therefore, to maximize the integer itself, we must place the largest digits on the LEFT.
        }
        
        // Let's rewrite the greedy choice properly:
        // Since score depends only on the multiset of digits (sum of squares), 
        // all permutations of a chosen set of digits yield the same score.
        // To maximize the resulting number, we should place the largest possible digits 
        // starting from the leftmost position.
        
        for (int i = 0; i < num; i++) {
            remainingDigits--;
            // Try digits from 9 down to 0 for the current position
            for (int d = 9; d >= 0; d--) {
                // If we pick digit 'd', can the remaining digits form (remainingSum - d)?
                // They must be able to sum up to (remainingSum - d) using `remainingDigits` slots,
                // meaning (remainingSum - d) <= 9 * remainingDigits
                // and also (remainingSum - d) >= 0 (and if it's the very first digit, it can't be 0 unless num == 1)
                if (i == 0 && d == 0 && num > 1) continue; // Leading zero not allowed
                
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
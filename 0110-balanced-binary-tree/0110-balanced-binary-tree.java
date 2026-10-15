class Solution {
    boolean ans = true;
    public int dfs(TreeNode curr) {
        if((curr.left != null) && (curr.right != null)) { 
            int L = dfs(curr.left) , R = dfs(curr.right);
            int T = L + R + 1;
            ans &= (Math.abs(L - R) <= 1);
            return Math.max(L , R) + 1;
        }   

        if(curr.left != null) {
            int T =  dfs(curr.left) + 1;
            ans &= (T <= 2);
            return T;
        }    

        if(curr.right != null) {
            int T =  dfs(curr.right) + 1;
            ans &= (T <= 2);
            return T;
        }   

        return 1;                   
    }

    public boolean isBalanced(TreeNode root) {
        if(root == null) 
            return true;
            
        ans = true;
        dfs(root);
        return ans;
    }
}
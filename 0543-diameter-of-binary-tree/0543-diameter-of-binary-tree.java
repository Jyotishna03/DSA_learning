/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = 0;
    public int dfs(TreeNode curr) {
        if((curr.left != null) && (curr.right != null)) { 
            int L = dfs(curr.left) , R = dfs(curr.right);
            int T = L + R + 1;
            ans = Math.max(ans , T);
            
            // System.out.println(curr.val + " " + T);

            return Math.max(L , R) + 1;
        }   

        if(curr.left != null) {
            int T =  dfs(curr.left) + 1;
            ans = Math.max(ans , T);

            //  System.out.println(curr.val + " " + T);

            return T;
        }    

        if(curr.right != null) {
            int T =  dfs(curr.right) + 1;
            ans = Math.max(ans , T);

            //  System.out.println(curr.val + " " + T);

            return T;
        }   

        return 1;                   
    }

    public int diameterOfBinaryTree(TreeNode root) {
        ans = 0;
        dfs(root);  

        return Math.max(ans - 1 , 0);      
    }
}
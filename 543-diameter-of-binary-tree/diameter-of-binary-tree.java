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
    private int ans;
    public int diameterOfBinaryTree(TreeNode root) { 
        ans=0;
        fun(root);
        return ans;
    }
    int fun(TreeNode root){
        if(root==null)return 0;
        int l=fun(root.left);
        int r=fun(root.right);
        ans=Math.max(ans,l+r);
        return Math.max(l,r)+1;
    }
}
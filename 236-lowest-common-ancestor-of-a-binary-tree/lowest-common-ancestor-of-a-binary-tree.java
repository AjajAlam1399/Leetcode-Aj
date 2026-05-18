/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return fun(root, p ,q);
    }

    private TreeNode fun(TreeNode root , TreeNode p , TreeNode q){
        if(root == null || Integer.compare(root.val,p.val)==0 || Integer.compare(root.val,q.val)==0){
            return root;
        }

        TreeNode l = fun(root.left , p ,q);
        TreeNode r = fun(root.right,p , q);

        if(l!=null & r!=null) return root;

        if(l!=null) return l;
        return r;
    }
}
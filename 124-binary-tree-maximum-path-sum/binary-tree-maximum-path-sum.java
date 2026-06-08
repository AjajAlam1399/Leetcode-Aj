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
    public int maxPathSum(TreeNode root) {
        AtomicInteger ans = new AtomicInteger(Integer.MIN_VALUE);
        fun(root, ans);
        return ans.get();
    }

    int fun(TreeNode root, AtomicInteger ans) {
        if (root == null)
            return 0;

        int left = Math.max(0, fun(root.left, ans));
        int right = Math.max(0, fun(root.right, ans));
        int curr = ans.get();
        curr = Math.max(curr, left+root.val);
        curr = Math.max(curr, right+root.val);
        curr = Math.max(curr, left + right + root.val);
        ans.set(curr);

        // System.out.println(ans);

        return Math.max(left, right) + root.val;
    }
}
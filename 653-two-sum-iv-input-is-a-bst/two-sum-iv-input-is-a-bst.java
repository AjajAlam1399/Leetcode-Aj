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
    Stack<TreeNode> left;
    Stack<TreeNode> right;

    void build(TreeNode root) {
        left= new Stack<>();
        right = new Stack<>();
        insertLeft(root, left);
        insertRight(root, right);
    }

    void insertLeft(TreeNode node, Stack<TreeNode> st) {
        TreeNode temp = node;
        while (temp != null) {
            st.push(temp);
            temp = temp.left;
        }
    }

    void insertRight(TreeNode node, Stack<TreeNode> st) {
        TreeNode temp = node;
        while (temp != null) {
            st.push(temp);
            temp = temp.right;
        }
    }

    TreeNode getNext(Stack<TreeNode> st) {
        if (st.isEmpty())
            return null;
        TreeNode node = st.pop();
        insertLeft(node.right, st);
        return node;
    }

    TreeNode getPrev(Stack<TreeNode> st) {
        if (st.isEmpty())
            return null;
        TreeNode node = st.pop();
        insertRight(node.left, st);
        return node;
    }

    public boolean findTarget(TreeNode root, int k) {
        build(root);

        TreeNode next = getNext(left);
        TreeNode prev = getPrev(right);

        while (true) {

            if (next == null || prev == null || next==prev)
                return false;

            if(next.val + prev.val == k) return true;
            else if(next.val + prev.val < k){
                next = getNext(left);
            }
            else if(next.val + prev.val > k){
                prev = getPrev(right);
            }

        }
    }
}
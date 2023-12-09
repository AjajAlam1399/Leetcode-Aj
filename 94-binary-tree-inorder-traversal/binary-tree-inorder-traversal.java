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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer>list=new ArrayList<>();
        Stack<TreeNode>st=new Stack<>();
        TreeNode temp=root;
        while(true){
            while(temp!=null){
                st.push(temp);
                temp=temp.left;
            }
            if(st.empty()==true){
                break;
            }
            TreeNode node=st.peek();
            list.add(node.val);
            st.pop();
            temp=node.right;

        }

        return list;
    }
}
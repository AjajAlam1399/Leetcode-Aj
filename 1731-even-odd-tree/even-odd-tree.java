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
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode>q=new LinkedList<>();
        q.offer(root);
        boolean flag=true;

        while(!q.isEmpty()){
            int val=q.peek().val;
            int size=q.size();
            for(int i=0;i<size;i++){
                    TreeNode node=q.poll();
                    if(node.left!=null){
                        q.offer(node.left);
                    }
                    if(node.right!=null){
                        q.offer(node.right);
                    }
                if(flag){
                    if(i==0){
                        if(val%2==0){
                            return false;
                        }
                    }
                    else{
                        if(node.val%2==0 || val>=node.val){
                            return false;
                        }
                        val=node.val;
                    }
                }
                else{
                    if(i==0){
                        if(val%2!=0){
                            return false;
                        }
                    }
                    else{
                        if(node.val%2!=0 || node.val>=val){
                            return false;
                        }
                        val=node.val;
                    }
                }
            }
            flag=!flag;
        }
        return true;
    }
}
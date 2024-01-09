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
    private int ind;
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        
        List<Integer>list=new ArrayList<>();
         ind=0;
        fun1(root1,list);
        // System.out.println(list);
        boolean ans=fun2(root2,list);
        // System.out.println(ind);
        if(!ans)return false;
        if(ind<list.size())return false;
        return true;
    }
    boolean isLeaf(TreeNode root1){
        if(root1.left==null && root1.right==null)return true;
        return false;
    }
    void fun1(TreeNode root,List<Integer>list){
        if(root==null)return ;
        if(isLeaf(root)){
            list.add(root.val);
            return;
        }
        fun1(root.left,list);
        fun1(root.right,list);
    }

    boolean fun2(TreeNode root,List<Integer>list){
        if(root==null)return true;
        if(isLeaf(root)){
            if(ind>=list.size())return false;
            if(list.get(ind)!=root.val)return false;
            ind++;
            // System.out.println(ind);
            return true;
        }
        if(!fun2(root.left,list))return false;
        if(!fun2(root.right,list))return false;
        return true;
    }
}
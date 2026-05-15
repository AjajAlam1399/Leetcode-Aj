/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root==null){
            return "N";
        }
        Queue<TreeNode>q = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        q.offer(root);
        sb.append(String.valueOf(root.val));

        while(!q.isEmpty()){
            TreeNode node = q.poll();
            if(node.left!=null){
                sb.append("#"+String.valueOf(node.left.val));
                q.offer(node.left);
            }
            else{
                sb.append("#N");
            }

            if(node.right!=null){
                sb.append("#"+String.valueOf(node.right.val));
                q.offer(node.right);
            }
            else{
                sb.append("#N");
            }
        }
        return sb.toString();

    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.equals("N"))return null;
        String [] str = data.split("#");
        TreeNode root = new TreeNode(Integer.valueOf(str[0]));
        Queue<TreeNode>q = new LinkedList<>();
        q.offer(root);
        int ind=1;
        while(ind<str.length){
            TreeNode node = q.poll();
            if(ind<str.length){
                String tempStr = str[ind];
                if(!tempStr.equals("N")){
                    node.left = new TreeNode(Integer.valueOf(tempStr));
                    q.offer(node.left);
                }
                ind++;
            }
            if(ind<str.length){
                String tempStr = str[ind];
                if(!tempStr.equals("N")){
                    node.right = new TreeNode(Integer.valueOf(tempStr));
                    q.offer(node.right);
                }
                ind++;
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
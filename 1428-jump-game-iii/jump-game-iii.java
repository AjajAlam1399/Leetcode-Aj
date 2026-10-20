class Solution {
    boolean [] visted;
    public boolean canReach(int[] arr, int start) {
        int n=arr.length;
        visted = new boolean [n];
        return dfs(start,arr);
    }

    boolean dfs(int node , int arr[]){
        if(node<0 || node>=arr.length || visted[node]) return false;
        if(arr[node]==0) return true;
        visted[node] = true;

        if(dfs(node+arr[node],arr) | dfs(node-arr[node],arr))return true;
        return false;

    }
}
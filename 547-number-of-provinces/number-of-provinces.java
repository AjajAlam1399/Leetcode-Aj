class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n=isConnected.length;
        List<List<Integer>> graph = new ArrayList<>();

        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    graph.get(i).add(j);
                }
            }
        }

        boolean [] visted = new boolean[n];
        Arrays.fill(visted,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!visted[i]){
                ans++;
                dfs(i,graph,visted);
            }
        }
        return ans;
    }

    void dfs(int node ,List<List<Integer>> graph , boolean [] visted  ){
        visted[node]=true;

        for(Integer adjNode : graph.get(node)){
            if(!visted[adjNode]){
                dfs(adjNode , graph , visted);
            }
        }
    }
}
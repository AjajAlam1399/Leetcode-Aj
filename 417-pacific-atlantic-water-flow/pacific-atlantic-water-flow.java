class Solution {
    int arr1[]={-1,0,1,0};
    int arr2[]={0,-1,0,1};

    private class Pair{
        public int first;
        public int second;
        public Pair(int first,int second){
            this.first=first;
            this.second=second;
        }
    };
    public List<List<Integer>> pacificAtlantic(int[][] heights) {

        int n=heights.length;
        int m=heights[0].length;

        int [][] p=pacific(heights);
        int [][] a=atlantic(heights);

       List<List<Integer>>ans=new ArrayList<>();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j]==1 && a[i][j]==1){
                    ans.add(Arrays.asList(i,j));
                }
            }
        }

        return ans;
    }

    int [][] pacific(int[][] heights){
        int n=heights.length;
        int m=heights[0].length;

        int [][]ans=new int[n][m];

        for(int i=0;i<n;i++){
            Arrays.fill(ans[i],0);
        }

        Queue<Pair> q = new LinkedList<>();

        for(int i=0;i<n;i++){
            q.offer(new Pair(i,0));
            ans[i][0]=1;
        }

        for(int i=0;i<m;i++){
            q.offer(new Pair(0,i));
            ans[0][i]=1;
        }

        while(!q.isEmpty()){
            Pair it = q.peek();
            q.poll();
            int x=it.first;
            int y=it.second;

            for(int k=0;k<4;k++){
                int newx=x+arr1[k];
                int newy=y+arr2[k];

                if(newx>=0 && newy>=0 && newx<n && newy<m && 
                ans[newx][newy]!=1 && heights[newx][newy]>=heights[x][y]){
                    q.offer(new Pair(newx,newy));
                    ans[newx][newy]=1;
                }
            }
        }

        return ans;
    }

    int [][] atlantic(int [][] heights){
        int n=heights.length;
        int m=heights[0].length;

        int [][]ans=new int[n][m];

        for(int i=0;i<n;i++){
            Arrays.fill(ans[i],0);
        }

        Queue<Pair> q = new LinkedList<>();

        for(int i=0;i<n;i++){
            q.offer(new Pair(i,m-1));
            ans[i][m-1]=1;
        }

        for(int i=0;i<m;i++){
            q.offer(new Pair(n-1,i));
            ans[n-1][i]=1;
        }

        while(!q.isEmpty()){
            Pair it = q.peek();
            q.poll();
            int x=it.first;
            int y=it.second;

            for(int k=0;k<4;k++){
                int newx=x+arr1[k];
                int newy=y+arr2[k];

                if(newx>=0 && newy>=0 && newx<n && newy<m && 
                ans[newx][newy]!=1 && heights[newx][newy]>=heights[x][y]){
                    q.offer(new Pair(newx,newy));
                    ans[newx][newy]=1;
                }
            }
        }

        return ans;
    }
}
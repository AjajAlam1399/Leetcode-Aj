class Solution {
    int arr1[]={-1,0,1,0};
    int arr2[]={0,-1,0,1};
    private class group{
        int h,x,y;
        public group(int h,int x,int y){
            this.h=h;
            this.x=x;
            this.y=y;
        }
    };
    public int trapRainWater(int[][] map) {
        int n=map.length;
        int m=map[0].length;
        int visted[][]=new int[n][m];

        for(int i=0;i<n;i++){
            Arrays.fill(visted[i],0);
        }

        PriorityQueue<group> pq =new PriorityQueue<>((a,b)->a.h-b.h);

        for(int i=0;i<m;i++){
            pq.offer(new group(map[0][i],0,i));
            visted[0][i]=1;
            pq.offer(new group(map[n-1][i],n-1,i));
            visted[n-1][i]=1;
        }

        for(int j=0;j<n;j++){
            pq.offer(new group(map[j][0],j,0));
            visted[j][0]=1;
            pq.offer(new group(map[j][m-1],j,m-1));
            visted[j][m-1]=1;
        }

        int ans=0;

        while(!pq.isEmpty()){
            group it = pq.peek();
            pq.poll();
            int currVal=it.h;
            int x=it.x;
            int y=it.y;

            for(int k=0;k<4;k++){
                int newx=x+arr1[k];
                int newy=y+arr2[k];

                if(newx>=0 && newy>=0 && newx<n && newy<m && 
                visted[newx][newy]==0){
                    visted[newx][newy]=1;
                    if(currVal>map[newx][newy]){
                        ans+=currVal-map[newx][newy];
                    }
                    pq.offer(new group(Math.max(currVal, map[newx][newy]), newx, newy));
                }
            }
        }

        return ans;
    }
}
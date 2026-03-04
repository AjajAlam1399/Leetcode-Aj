class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int [] vec = new int[n];

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]!=0){
                    break;
                }
                cnt++;
            }
            vec[i] = cnt;
        }

        int ans =0;

        // for(int i=0;i<n;i++){
        //     System.out.println(vec[i]);
        // }

        for(int i=0;i<n;i++){
            int req = n-i-1;
            if(vec[i]>=req){
                continue;
            }
            int j=i+1;
            while(j<n && vec[j]<req){
                j++;
            }
            if(j>=n ||vec[j]<req)return -1;
            while(j!=i){
                int temp = vec[j];
                vec[j]=vec[j-1];
                vec[j-1] =temp;
                j--;
                ans++;
            }
        }
        return ans;
    }
}
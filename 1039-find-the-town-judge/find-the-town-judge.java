class Solution {
    public int findJudge(int n, int[][] trust) {
        int out[]=new int[n+1];
        int in[]=new int[n+1];
        Arrays.fill(out,0);
        Arrays.fill(in,0);
        for(int i=0;i<trust.length;i++){
            out[trust[i][0]]++;
            in[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(in[i]==n-1 && out[i]==0){
                return i;
            }
        }
        return -1;
    }
}
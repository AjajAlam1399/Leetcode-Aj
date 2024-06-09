class Solution {
    public int numberOfChild(int n, int k) {
        int cnt=0;
        int dir=0;
        while(k>0){
            if(dir==0){
                cnt++;
                if(cnt==n-1){
                    dir=1;
                }
            }
            else if(dir==1){
                cnt--;
                if(cnt==0){
                    dir=0;
                }
            }
            k--;
        }
        return cnt;
    }
}
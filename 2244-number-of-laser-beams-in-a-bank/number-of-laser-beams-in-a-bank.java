class Solution {
    public int numberOfBeams(String[] bank) {
        int n=bank.length;
        int m=bank[0].length();
        int prev=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<m;j++){
                if(bank[i].charAt(j)=='1'){
                    curr++;
                }
            }
            if(prev!=0 && curr!=0){
                ans+=prev*curr;
                prev=curr;
            }
            else{
                if(curr!=0 && prev==0){
                    prev=curr;
                }
            }
        }
        return ans;
    }
}
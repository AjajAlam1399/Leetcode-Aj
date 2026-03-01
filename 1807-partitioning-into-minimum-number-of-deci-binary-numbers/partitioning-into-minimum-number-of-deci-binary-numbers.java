class Solution {
    public int minPartitions(String s) {
        
        int n = s.length();
        int ans =0;

        for(int i=0;i<n;i++){
            int chNum = (int)s.charAt(i) - (int)'0';
            ans =Math.max(ans,chNum);
        }
        return ans;
    }
}
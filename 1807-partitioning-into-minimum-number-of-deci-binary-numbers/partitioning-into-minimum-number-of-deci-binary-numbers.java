class Solution {
    public int minPartitions(String n) {
        int size=n.length();
        int maxd=n.charAt(0)-'0';
        int ans=n.charAt(0)-'0';

        for(int i=1;i<size;i++){
            int num=n.charAt(i)-'0';
            if(num>maxd){
                ans+=num-maxd;
                maxd=num;
            }
        }
        return ans;
    }
}
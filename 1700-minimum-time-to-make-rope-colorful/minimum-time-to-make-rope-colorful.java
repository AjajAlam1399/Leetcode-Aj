class Solution {
    public int minCost(String colors, int[] neededTime) {
         int n=colors.length();
         char prevchar='1';
         int prevint=1;
        int ans=0;

        for(int i=0;i<n;i++){
                if(prevchar==colors.charAt(i)){
                    if(prevint<=neededTime[i]){
                        ans+=prevint;
                       prevchar=colors.charAt(i);
                       prevint=neededTime[i];
                    }
                    else{
                        ans+=neededTime[i];
                    }
                }
                else{
                   prevchar=colors.charAt(i);
                       prevint=neededTime[i];
                }
        }
        return ans;
    }
}
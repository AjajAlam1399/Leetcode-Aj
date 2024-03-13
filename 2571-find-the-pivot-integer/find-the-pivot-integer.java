class Solution {
    public int pivotInteger(int n) {
        int totalsum=((n)*(n+1))/2;
        // System.out.println(totalsum);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=i;
            int sum2=totalsum-sum+i;
            if(sum==sum2){
                return i;
            }
            if(sum>sum2){
                break;
            }
        }
        return -1;
    }
}
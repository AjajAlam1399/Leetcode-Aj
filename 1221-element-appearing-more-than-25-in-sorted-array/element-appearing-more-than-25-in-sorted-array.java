class Solution {
    public int findSpecialInteger(int[] arr) {
        
        double ansper=0.25;
        int n=arr.length;
        int e=0;
        int cnt=1;
        int ans=0;
        while(e<n){
            int num=arr[e];
            while(e+1<n && arr[e]==arr[e+1]){
                e++;
                cnt++;
            }
            double currans=(double)cnt/(double)n;
            if(currans>ansper){
                ans=num;
                break;
            }
            cnt=1;
            e++;
        }
        return ans;
    }
}
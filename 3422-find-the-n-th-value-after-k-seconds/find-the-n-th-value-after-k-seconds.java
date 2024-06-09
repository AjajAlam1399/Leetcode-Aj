class Solution {
    int mod=1000000000+7;
    public int valueAfterKSeconds(int n, int k) {
        int arr[]=new int[n];
        Arrays.fill(arr,1);
        int ind=1;
        while(k>0){
           for(int i=1;i<n;i++){
            arr[i]=(arr[i]%mod+arr[i-1]%mod)%mod;
           }
           k--;
        }
        return arr[n-1];
    }
}
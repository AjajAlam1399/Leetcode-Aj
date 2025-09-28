class Solution {
    public int largestPerimeter(int[] nums) {
        
        int arr[]=Arrays.stream(nums).boxed().sorted((a,b)->b-a).mapToInt(Integer::intValue).toArray();

        int ans=0;
        for(int i=0;i<arr.length-2;i++){
            int a=arr[i];
            int b=arr[i+1];
            int c=arr[i+2];

            if(a==0 || b==0 || c==0){
                break;
            }
            if(b+c>a){
                ans=Math.max(ans,a+b+c);
            }
        }

        return ans;
    }
}
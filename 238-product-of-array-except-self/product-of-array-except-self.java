class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n=nums.length;
        int[] product=new int[n];
        int pro=1;
        for(int i=0;i<n;i++){
            product[i]=pro;
            pro*=nums[i];
        }
        pro=1;

        for(int i=n-1;i>=0;i--){
            product[i]*=pro;
            pro*=nums[i];
        }

        return product;
    }
}
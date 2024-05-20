class Solution {
    int sum;
    public int subsetXORSum(int[] nums) {
        sum=0;
        ArrayList<Integer>list=new ArrayList<>();
        fun(0,nums,list);
        return sum;
    }
    void fun(int ind,int nums[],ArrayList<Integer>list){
        if(ind==nums.length){
            int curr=0;
            for(int num:list)curr^=num;
            sum+=curr;
            return;
        }
        
        fun(ind+1,nums,list);
        list.add(nums[ind]);
        fun(ind+1,nums,list);
        list.remove(list.size()-1);
    }
}
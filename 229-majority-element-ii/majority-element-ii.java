class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n=nums.length;
        int num1=Integer.MAX_VALUE, num2=Integer.MAX_VALUE ,cnt1=0 ,cnt2 = 0;

        for(int i=0;i<n;i++){
            if(Integer.compare(nums[i],num1)==0){
                cnt1++;
            }
            else if(Integer.compare(nums[i],num2)==0){
                cnt2++;
            }
            else if(cnt1==0){
                num1 = nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                num2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0;cnt2=0;

        for(int i=0;i<n;i++){
            if(Integer.compare(nums[i],num1)==0){
                cnt1++;
            }
            else if(Integer.compare(nums[i],num2)==0){
                cnt2++;
            }
        }
        List<Integer>ans = new ArrayList<>();

        if(cnt1>n/3){
            ans.add(num1);
        }
        if(cnt2>n/3){
            ans.add(num2);
        }

        return ans;
    }
}
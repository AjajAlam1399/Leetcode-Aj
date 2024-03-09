class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int ans=-1;
        Map<Integer,Integer>map=new HashMap<>();
        for(int i=0;i<nums1.length;i++){
            map.put(nums1[i],1);
        }
        for(int i=0;i<nums2.length;i++ ){
            if(map.containsKey(nums2[i])){
                ans=nums2[i];
                break;
            }
        }

        return ans;
    }
}
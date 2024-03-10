class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Map<Integer,Integer>map=new HashMap<>();
        for(int i=0;i<nums1.length;i++){
            map.computeIfAbsent(nums1[i],k->1);
        }
        Set<Integer>set=new HashSet<>();
        for(int i=0;i<nums2.length;i++){
            if(map.containsKey(nums2[i])){
                set.add(nums2[i]);
            }
        }
        int n=set.size();
        int ans[]=new int[n];
        int i=0;
        for(int val:set){
            ans[i]=val;
            i++;
        } 
        return ans;
    }
}
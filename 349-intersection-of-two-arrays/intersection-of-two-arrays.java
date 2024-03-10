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
        return set.stream().mapToInt(x->x).toArray();
    }
}
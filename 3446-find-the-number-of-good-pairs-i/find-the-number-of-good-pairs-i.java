class Solution {
    public int numberOfPairs(int[] nums1, int[] nums2, int k) {

        int cnt = 0;

        for (int i = 0; i < nums2.length; i++) {
            int val = nums2[i] * k;
            for (int j = 0; j < nums1.length; j++) {
                if (nums1[j] % val == 0)
                    cnt++;
            }
        }
        return cnt;
    }
}
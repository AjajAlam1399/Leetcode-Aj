class Solution {
    int sum;
    int bitmask;

    public int subsetXORSum(int[] nums) {
        sum = 0;
        bitmask=0;
        fun(0, nums);
        return sum;
    }

    void fun(int ind, int nums[]) {
        if (ind == nums.length) {
            int curr = 0;
            for (int i = 0; i <nums.length; i++) {
                int bit = ((bitmask) & (1<<i));
                if (bit!=0) {
                    curr ^= nums[i];
                }
            }
            sum += curr;
            return;
        }
        fun(ind + 1, nums);
        bitmask |= (1 << ind);
        fun(ind + 1, nums);
        bitmask&=~(1 << ind);
    }
}
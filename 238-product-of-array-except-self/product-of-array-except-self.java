class Solution {
    public int[] productExceptSelf(int[] nums) {
        List<Integer> prefixProducts = new ArrayList<>();
        prefixProducts.add(1);
        for (int i = 0; i < nums.length - 1; i++) {
            prefixProducts.add(prefixProducts.get(i) * nums[i]);
        }
        int ans[] = new int[nums.length];
        int suffixProduct = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            ans[i] = prefixProducts.get(i) * suffixProduct;
            suffixProduct *= nums[i];
        }
        return ans;
    }
}
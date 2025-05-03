class Solution {
    vector<int> BIT;
    int n;
    void update(int i){
        for(; i < BIT.size(); i += (i & -i))
            BIT[i]++;
    }
    int sum(int i){
        int ret  =0;
        for(; i > 0; i -= (i& -i))
            ret += BIT[i];
        return ret;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        n = nums.size();
        vector<long> psum(1+n, 0);
        for(int i =0; i <n; ++i)
            psum[i+1] = psum[i] + nums[i];
        vector<long> sorted_psum(psum);
        sort(sorted_psum.begin(), sorted_psum.end());
    
        unordered_map<int, int> rank;
        for(int i =0; i <= n ; ++i)
            rank[sorted_psum[i]] = 1+i;
        BIT.resize(2+n, 0);
        int ans =0;
        for(int i =0; i <= n ; ++i){
            long  up = psum[i] - lower;
            long lo = psum[i] - upper;

            int lower_idx  =  lower_bound(sorted_psum.begin(), sorted_psum.end(), lo)-sorted_psum.begin();
            int higher_idx  = upper_bound(sorted_psum.begin(), sorted_psum.end(), up)-sorted_psum.begin();
            ans += sum(higher_idx) - sum (lower_idx);
            update(rank[psum[i]]);
        }
        return ans;
    }
};
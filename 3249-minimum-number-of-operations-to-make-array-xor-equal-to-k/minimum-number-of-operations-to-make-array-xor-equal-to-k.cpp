class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xornum=0;
        for(int i=0;i<nums.size();i++){
            xornum^=nums[i];
        }
        int cnt=0;
        for(int i=0;i<32;i++){
            int bit1=((xornum)&(1<<i));
            int bit2=((k)&(1<<i));
            if(bit1!=bit2)cnt++;
        }
        return cnt;
    }
};
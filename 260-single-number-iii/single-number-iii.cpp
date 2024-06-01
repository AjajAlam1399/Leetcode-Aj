class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorele=0,n=nums.size();

        for(int i=0;i<n;i++){
            xorele^=nums[i];
        }
        int ind=0;
        while(true){
            int bit=(xorele)&(1<<ind);
            if(bit){
                break;
            }
            ind++;
        }
        int prevxor=xorele;
        for(int i=0;i<n;i++){
            int bit=(nums[i]&(1<<ind));
            if(bit)xorele^=nums[i];
        }
        vector<int>ans;
        ans.push_back(xorele);
        ans.push_back(xorele^prevxor);
        return ans;
    }
};
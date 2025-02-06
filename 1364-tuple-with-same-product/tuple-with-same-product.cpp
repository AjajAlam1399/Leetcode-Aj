class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,set<pair<int,int>>>map;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int num1=nums[i];
            for(int j=i+1;j<n;j++){
                int num2=nums[j];
                map[num1*num2].insert({num1,num2});
            }
        }
        long long cnt=0;

        for(auto it: map){
            int size=0;
            for(auto it1=it.second.begin();
            it1!=it.second.end();it1++){
                size++;
            }
            long long pair=((size)*(size-1))/2;
            cnt+=8*pair;
        }
        return cnt;
    }
};
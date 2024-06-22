class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {

        int n=nums.size(),ans=0;
        unordered_set<string>set;

        for(int i=0;i<n;i++){
            int cnt=0;
            string str="";
            for(int j=i;j<n;j++){
                str+=to_string(nums[j])+"#";
                if(nums[j]%p==0)cnt++;
                if(cnt<=k){
                    if(set.find(str)==set.end())set.insert(str);
                }
                else break;
            }
        }
        return set.size();
        
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        int ans=1;

        for(int i=0;i<n;i++){
            if(map[nums[i]]>=2){
                int p=1;
                int num=nums[i];
                if(num==1){
                    if(map[num]%2!=0){
                        ans=max(ans,map[num]);
                    }
                    else{
                        ans=max(map[num]-1,ans);
                    }
                    continue;
                }
                while(map.find((long long)pow(num,2))!=map.end()){
                    ans=max(ans,2*p+1);
                    if(map[(long long)pow(num,2)]>=2){
                        p++;
                        num=(long long)pow(num,2);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
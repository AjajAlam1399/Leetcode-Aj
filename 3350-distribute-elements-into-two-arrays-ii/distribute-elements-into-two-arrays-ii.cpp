class BIT{
    vector<int>bit;
    public:
    BIT(int n){
        bit.resize(n+1);
    }
    void update(int idx){
        int n=bit.size();
        while(idx<=n-1){
            bit[idx]+=1;
            idx+=(idx&-idx);
        }
    }
    int count(int idx){
        int sum=0;
        while(idx>0){
            sum+=bit[idx];
            idx-=(idx&-idx);
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        vector<int>vec1;
        vector<int>vec2;
        int n=nums.size();

        vector<int>vec(nums.begin(),nums.end());

        sort(vec.begin(),vec.end());
        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            map[vec[i]]=i+1;
        }

        vec1.push_back(nums[0]);
        vec2.push_back(nums[1]);

        BIT bit1(n);
        BIT bit2(n);
        bit1.update(map[nums[0]]);
        bit2.update(map[nums[1]]);

        for(int i=2;i<n;i++){
            int cnt1=vec1.size()- bit1.count(map[nums[i]]);
            int cnt2=vec2.size()-bit2.count(map[nums[i]]);
            if(cnt1>cnt2){
                vec1.push_back(nums[i]);
                bit1.update(map[nums[i]]);
            }
            else if(cnt1<cnt2){
                vec2.push_back(nums[i]);
                bit2.update(map[nums[i]]);
            }
            else{
                if(vec1.size()<=vec2.size()){
                    vec1.push_back(nums[i]);
                    bit1.update(map[nums[i]]);
                }
                else{
                vec2.push_back(nums[i]);
                bit2.update(map[nums[i]]);
                }
            }
        }

        vector<int>ans(vec1.begin(),vec1.end());
        ans.insert(ans.end(),vec2.begin(),vec2.end());

        return ans;

    }
};
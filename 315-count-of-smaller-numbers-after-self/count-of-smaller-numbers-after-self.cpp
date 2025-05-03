class Solution {
    vector<int>bit;
    int N;
public:
    vector<int> countSmaller(vector<int>& nums) {
        unordered_map<int,int>map;

        vector<int>vec(nums.begin(),nums.end());
        sort(vec.begin(),vec.end());

        N=nums.size()+1;
        bit.resize(N);

        for(int i=0;i<nums.size();i++){
            map[vec[i]]=i+1;
        }
        vector<int>ans(N-1);
        for(int i=nums.size()-1;i>=0;i--){
            int ind=map[nums[i]];
            ans[i]=get(ind-1);
            update(ind);
        }

        return ans;

    }

    void update(int i){
        while(i<N){
            bit[i]+=1;
            i+=(i&(-i));
        }
    }

    int get(int i){
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=(i&(-i));
        }
        return sum;
    }
};
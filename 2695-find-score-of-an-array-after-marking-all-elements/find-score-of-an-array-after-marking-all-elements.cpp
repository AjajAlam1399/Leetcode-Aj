class Solution {
    using vec=pair<int,int>;
public:
    long long findScore(vector<int>& nums) {
        priority_queue<vec,vector<vec>,greater<vec>>pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        long long ans=0;
        unordered_set<int>marked;

        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            if(marked.find(it.second+1)==marked.end() && marked.find(it.second-1)==marked.end()){
                ans+=it.first;
                marked.insert(it.second);
            }
        }
        return ans;
    }
};
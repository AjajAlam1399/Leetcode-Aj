class Solution {
    using vec=vector<int>;
public:
    long long findScore(vector<int>& nums) {
        priority_queue<vec,vector<vec>,greater<vec>>pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i,i-1,i+1});
        }

        long long ans=0;
        unordered_set<int>marked;

        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            if(marked.find(it[1])==marked.end()){
                ans+=it[0];
                marked.insert(it[1]);
                marked.insert(it[2]);
                marked.insert(it[3]);
            }
        }
        return ans;
    }
};
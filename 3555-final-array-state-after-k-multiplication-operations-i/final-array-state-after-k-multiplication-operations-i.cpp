class Solution {
    using pp=pair<int,int>;
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k){
            auto it =pq.top();
            pq.pop();
            it.first=it.first*multiplier;
            pq.push(it);
            k--;
        }
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            nums[it.second]=it.first;
        }
        return nums;
    }
};
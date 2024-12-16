class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {

        set<int>set;
        for(auto num:nums){
            set.insert(num);
        }

        for(int i=0;i<moveFrom.size();i++){
            auto it=set.find(moveFrom[i]);
            if(it!=set.end()){
                set.erase(it);
                set.insert(moveTo[i]);
            }
        }

        vector<int>ans;

        for(auto it=set.begin();it!=set.end();it++){
            ans.push_back(*it);
        }

        return ans;
    }
};
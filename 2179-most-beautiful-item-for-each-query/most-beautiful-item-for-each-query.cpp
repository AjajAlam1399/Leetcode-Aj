class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n1=items.size(),n2=queries.size();
        vector<pair<int,int>>vec;
        vector<int>ans(n2);
        for(int i=0;i<n2;i++){
            vec.push_back({queries[i],i});
        }
        sort(vec.begin(),vec.end());
        sort(items.begin(),items.end());
        int currmax=0,i=0,j=0;
        while(j<n2){
            while(i<n1 && vec[j].first>=items[i][0]){
                currmax=max(currmax,items[i][1]);
                i++;
            }
            ans[vec[j].second]=currmax;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        ans.push_back(newInterval);
        int i=0,n=intervals.size();

        while(i<n){
            vector<int> prev=ans.back();
            ans.pop_back();
            if(intervals[i][0]<prev[0] && intervals[i][1]<prev[0]){
                ans.push_back(intervals[i]);
                ans.push_back(prev);
            }
            else if(prev[1]<intervals[i][0] && prev[1]<intervals[i][1]){
                ans.push_back(prev);
                ans.push_back(intervals[i]);
            }
            else{
                int start=min(prev[0],intervals[i][0]);
                int end=max(prev[1],intervals[i][1]);
                ans.push_back({start,end});
            }
            i++;
        }
        return ans;
    }
};
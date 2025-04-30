class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        auto comp = [&](const vector<int>& i, const vector<int>& j){
            if(i[0]==j[0])
                return i[1] > j[1];
            return i[0] < j[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        ans.push_back(intervals[0]);
        int k =0;
        for(int i =1; i< intervals.size(); ++i){
            if( (intervals[i][0]>= ans.back()[0]) and (intervals[i][1] <= ans.back()[1]))
            {
                ++k;
            }
            else if(intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else if ((intervals[i][0] > ans.back()[0]) and (intervals[i][0] <= ans.back()[1]) )
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return intervals.size()- k;
    }
};
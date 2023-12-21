class Solution {
    bool cmp(vector<int>vec1,vector<int>vec2){
        return vec1[0]-vec2[1];
    }
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(),points.end());
        for(int i=1;i<points.size();i++){
            auto p1=points[i-1];
            auto p2=points[i];
            ans=max(ans,p2[0]-p1[0]);
        }
        return ans;
    }
};
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>hor;
        vector<vector<int>>ver;

        for(int i=0;i<rectangles.size();i++){
            hor.push_back({rectangles[i][0],rectangles[i][2]});
            ver.push_back({rectangles[i][1],rectangles[i][3]});
        }

        sort(hor.begin(),hor.end());
        // for(auto it : hor){
        //     cout<<it[0]<<","<<it[1]<<"--";
        // }
        cout<<endl;
        int horcnt=0;
        auto prev=hor[0];
        for(int i=1;i<hor.size();i++){
            if(prev[1]<=hor[i][0]){
                horcnt++;
                prev=hor[i];
            }
            else{
                if(prev[1]<hor[i][1]){
                    prev=hor[i];
                }
            }
        }
        if(horcnt>=2)return true;

        sort(ver.begin(),ver.end());
        // for(auto it : ver){
        //     cout<<it[0]<<","<<it[1]<<"--";
        // }
        // cout<<endl;
        int vercnt=0;
         prev=ver[0];
        for(int i=1;i<ver.size();i++){
            // cout<<prev[0]<<","<<prev[1]<<endl;
            if(prev[1]<=ver[i][0]){
                vercnt++;
                prev=ver[i];
            }
            else{
                if(prev[1]<ver[i][1]){
                    prev=ver[i];
                }
            }
        }
        if(vercnt>=2)return true;
        return false;
    }
};
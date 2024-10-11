class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
    
        int n=times.size();
        vector<vector<int>>vec;
        for(int i=0;i<times.size();i++){
            vec.push_back({times[i][0],times[i][1],i});
        }
        sort(vec.begin(),vec.end());
        vector<int>ch(n);

        for(int i=0;i<vec.size();i++){
            int s=vec[i][0];
            int e=vec[i][1];
            int pos=vec[i][2];
            int chair;
            for(int i=0;i<times.size();i++){
                if(ch[i]==0){
                    ch[i]=e;
                    chair=i;
                    break;
                }
                else if(ch[i]<=s){
                    ch[i]=e;
                    chair=i;
                    break;
                }
            }
            if(pos==targetFriend){
                return chair;
            }
        }
        return 0;

    }
};
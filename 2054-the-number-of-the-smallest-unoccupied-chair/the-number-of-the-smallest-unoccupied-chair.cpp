class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int chair=0;
        vector<vector<int>>vec;
        for(int i=0;i<times.size();i++){
            vec.push_back({times[i][0],times[i][1],i});
        }
        sort(vec.begin(),vec.end());
        unordered_map<int,int>map;
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<vec.size();i++){

            int s=vec[i][0];
            int e=vec[i][1];
            int pos=vec[i][2];
            vector<int>erase;
            for(auto it : map){
                if(it.second<=s){
                    pq.push(it.first);
                    erase.push_back(it.first);
                }
            }
            for(auto it : erase){
                map.erase(it);
            }
            int currchair=chair;
            if(!pq.empty()){
                currchair=pq.top();
                pq.pop();
            }
            else{
                chair++;
            }
            if(pos==targetFriend){
                return currchair;
            }
            map[currchair]=e;
        }
        return chair;
    }
};
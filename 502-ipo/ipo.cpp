class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>cont;


        for(int i=0;i<n;i++){
            cont.push_back({capital[i],profits[i]});
        }

        sort(cont.begin(),cont.end());

        int i=0;
        int taken=0;
        priority_queue<pair<int,int>>pq;
        int ans=w;
        while(i<n || !pq.empty()){
                while(i<n && cont[i].first<=ans){
                    pq.push({cont[i].second,cont[i].first});
                    i++;
                }
                if(pq.empty()){
                    break;
                }
                if(!pq.empty()){
                    auto it=pq.top();
                    pq.pop();
                    ans+=it.first;
                    taken++;
                }
                if(taken==k ){
                    break;
                }
        }

        return ans;
    }
};
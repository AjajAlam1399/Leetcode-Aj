class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int ans=0;
        int ind=0,n1=players.size(),n2=trainers.size();

        for(int i=0;i<n2;i++){
            if(ind<n1 && trainers[i]>=players[ind]){
                ans++;
                ind++;
            }
        }

        return ans;
    }
};
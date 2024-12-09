class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        int n=moveTime.size();
        int m=moveTime[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,
        greater<vector<int>>>pq;

        dist[0][0]=0;

        pq.push({0,0,0});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int currdist=it[0];
            int i=it[1];
            int j=it[2];

            int arr1[]={-1,0,1,0};
            int arr2[]={0,-1,0,1};

            for(int k=0;k<4;k++){
                int newi=i+arr1[k];
                int newj=j+arr2[k];

                if(newi>=0 && newj>=0 && newi<n && newj<m){
                    int time=currdist+1;
                    if(moveTime[newi][newj]>=time){
                        time=moveTime[newi][newj]+1;
                    }
                    if(dist[newi][newj]>time){
                        dist[newi][newj]=time;
                        pq.push({time,newi,newj});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
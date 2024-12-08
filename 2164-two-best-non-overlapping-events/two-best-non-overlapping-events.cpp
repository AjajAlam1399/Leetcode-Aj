class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());

        vector<int>vec(n,0);
        vec[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            vec[i]=max(vec[i+1],events[i][2]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int currans=events[i][2];
            int ind=bSearch(events,i+1,events[i][1]);
            if(ind!=-1){
                currans+=vec[ind];
            }
            ans=max(ans,currans);
        }
        return ans;
    }
    int bSearch(vector<vector<int>>& events,int s,int e){
        int n=events.size();
        int i=s,j=n-1;

        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(events[mid][0]>e){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};
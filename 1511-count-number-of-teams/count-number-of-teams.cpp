class Solution {
    using pp=pair<int,int>;
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        vector<pp>left(n);
        vector<pp>right(n);

        for(int i=0;i<n;i++){
            int lsm=0,lgt=0;
            int rsm=0,rgt=0;
            for(int j=0;j<i;j++){
                if(rating[j]>rating[i]){
                    lgt++;
                }
                else if(rating[j]<rating[i]){
                    lsm++;
                }
            }
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i]){
                    rgt++;
                }
                else if(rating[j]<rating[i]){
                    rsm++;
                }
            }
            left[i]={lsm,lgt};
            right[i]={rsm,rgt};
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(i!=0 && i!=n-1){
                ans+=left[i].first*right[i].second;
                ans+=left[i].second*right[i].first;
            }
        }
        return ans;
    }
};
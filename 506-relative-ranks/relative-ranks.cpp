class Solution {
    using pp=pair<int,int>;
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<pp>vec;

        for(int i=0;i<n;i++){
            vec.push_back({score[i],i});
        }
        sort(vec.rbegin(),vec.rend());
        vector<string>ans(n);

        for(int i=0;i<n;i++){
            if(i==0){
                ans[vec[i].second]="Gold Medal";
            }
            else if(i==1){
               ans[vec[i].second]="Silver Medal"; 
            }
            else if(i==2){
                ans[vec[i].second]="Bronze Medal"; 
            }
            else{
                ans[vec[i].second]=to_string(i+1);
            }
        }
        return ans;
    }
};
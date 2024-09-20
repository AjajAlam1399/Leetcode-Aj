bool cmp(vector<int>vec1,vector<int>&vec2){
    if(vec1[0]==vec2[0]){
        return vec1[1]>vec2[1];
    }
    return vec1[0]<vec2[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        int n=people.size();
        vector<int>vec(n,-1);

        for(int i=0;i<n;i++){
            cout<<people[i][0]<<" "<<people[i][1]<<endl;
            auto it =people[i];
            int cnt=0;
            int j=0;
            for(j=0;j<n;j++){
                if(cnt==it[1]){
                    break;
                }
                if(vec[j]==-1){
                    cnt++;
                }
                else {
                    if(people[vec[j]][0]>=it[0]){
                        cnt++;
                    }
                }
            }
            while(j<n){
                if(vec[j]==-1){
                    break;
                }
                j++;
            }
            vec[j]=i;
        }
        vector<vector<int>>ans(n);

        for(int i=0;i<n;i++){
            ans[i]=people[vec[i]];
        }

        return ans;

    }
};
class Solution {
    using pp=pair<int,int>;
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>vec(26,vector<long long>(26,1e8));

        for(int i=0;i<changed.size();i++){
            vec[original[i]-'a'][changed[i]-'a']=min(vec[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }


        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                        vec[i][j]=min(vec[i][j],vec[i][via]+vec[via][j]);
                }
            }
        }
        long long ans=0;

        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                if(vec[source[i]-'a'][target[i]-'a']==1e8)return -1;
                else ans+=vec[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};
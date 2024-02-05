class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>>vec(26);

        for(int i=0;i<s.size();i++){
            int ind=s[i]-'a';
            vec[ind].first++;
            vec[ind].second=i;
        }
        int ans=INT_MAX;

        for(int i=0;i<26;i++){
            if(vec[i].first==1){
                ans=min(ans,vec[i].second);
            }
        }

        return ans==INT_MAX?-1:ans;
    }
};
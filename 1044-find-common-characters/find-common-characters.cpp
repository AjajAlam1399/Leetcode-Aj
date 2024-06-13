class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>vec(n,vector<int>(26,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                vec[i][words[i][j]-'a']++;
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++){
            int cnt=INT_MAX;
            for(int j=0;j<n;j++){
                cnt=min(cnt,vec[j][i]);
            }
            for(int k=0;k<cnt;k++){
                char ch='a'+i;
                string str="";
                str.push_back(ch);
                ans.push_back(str);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>vec(26,0);

        for(int i=0;i<words2.size();i++){
            vector<int>vec1(26,0);
            for(int j=0;j<words2[i].size();j++){
                vec1[words2[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                vec[k]=max(vec[k],vec1[k]);
            }
        }

        for(int i=0;i<words1.size();i++){
            vector<int>vec1(26,0);
            for(int j=0;j<words1[i].size();j++){
                vec1[words1[i][j]-'a']++;
            }
            bool flag=true;
            for(int k=0;k<26;k++){
                if(vec[k]>vec1[k]){
                    flag=false;
                    break;
                }
            }
            if(flag)ans.push_back(words1[i]);
        }
        return ans;
    }
};
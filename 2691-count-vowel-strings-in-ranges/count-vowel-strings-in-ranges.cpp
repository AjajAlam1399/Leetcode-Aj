class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>vec(n);
        int sum=0;
        for(int i=0;i<n;i++){
            char s=words[i][0];
            char e=words[i][words[i].size()-1];
            if(isVowel(s) && isVowel(e))sum++;
            vec[i]=sum;
        }
        vector<int>ans;

        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int lval=l==0?0:vec[l-1];
            int currans=vec[r]-lval;
            ans.push_back(currans);
        }
        return ans;
    }

    bool isVowel(char ch){
        if(ch=='a' || ch=='e'|| ch=='i'|| ch=='o'||ch=='u')return true;
        return false;
    }
};
class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        string str="a";
        ans.push_back(str);
        for(int i=0;i<target.size();i++){
            while(str[str.size()-1]!=target[i]){
                char nextChar='a'+(str[str.size()-1]-'a'+1)%26;
                str[str.size()-1]=nextChar;
                ans.push_back(str);
            }
            if(str!=target){
                str.push_back('a');
                ans.push_back(str);
            }
        }
        return ans;
    }
};
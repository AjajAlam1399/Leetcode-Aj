class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        vector<int>ch(26,0);

        for(int i=0;i<chars.size();i++){
            ch[chars[i]-'a']++;
        }

        int ans=0;

        for(int i=0;i<words.size();i++){
            string str=words[i];
            bool flag=false;
            vector<int>vec(26,0);
            for(int j=0;j<str.size();j++){
                vec[str[j]-'a']++;
            }
            for(int k=0;k<26;k++){
                if(vec[k]>ch[k]){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ans+=str.size();
            }
        }

        return ans;
    }
};
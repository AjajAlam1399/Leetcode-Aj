class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>map;
        string str="";
        int n1=s1.size(),n2=s2.size(),i=0;

        while(i<n1){
            while(i<n1 && s1[i]!=' '){
                str.push_back(s1[i]);
                i++;
            }
            map[str]++;
            i++;
            str="";
        }
        i=0;
        while(i<n2){
            while(i<n2 && s2[i]!=' '){
                str.push_back(s2[i]);
                i++;
            }
            map[str]++;
            i++;
            str="";
        }

        vector<string>ans;

        for(auto it : map){
            if(it.second==1)ans.push_back(it.first);
        }
        return ans;

    }
};
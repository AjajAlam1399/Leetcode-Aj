class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_map<char,vector<int>>map;
        unordered_set<string>set;

        for(int i=0;i<n;i++){
            map[s[i]].push_back(i);
        }


        for(auto it:map){
            char ch=it.first;
            // cout<<ch<<endl;
            vector<int>vec=it.second;
            if(vec.size()>=2){
                for(int i=1;i<vec.size();i++){
                    int sind=vec[i-1]+1;
                    int eind=vec[i]-1;
                    while(sind<=eind){
                        string str="";
                        str.push_back(ch);
                        str.push_back(s[sind]);
                        str.push_back(ch);
                        // str+=ch+s[sind]+ch;
                        if(set.find(str)==set.end()){
                            set.insert(str);
                            // cout<<str<<endl;
                        }
                        sind++;
                    }
                }
            }
            if(vec.size()>=3){
                string str="";
                str.push_back(ch);str.push_back(ch);str.push_back(ch);
                // st+=ch+ch+ch;
                // cout<<str<<endl;
                set.insert(str);
            }
        }
        // for(auto st:set){
        //     cout<<st<<endl;
        // }

        return set.size();
    }
};
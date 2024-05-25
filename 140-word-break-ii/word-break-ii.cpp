class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        for(auto it  :wordDict)set.insert(it);
        vector<string>ans;
        fun(0,s,set,"",ans);
        return ans;
    }
    void fun(int ind,string &s,unordered_set<string>&set,string subans,vector<string>&ans){

        if(ind==s.size()){
            subans.pop_back();
            ans.push_back(subans);
            subans.push_back(' ');
            return ;
        }

        for(int i=ind;i<s.size();i++){
            string str=s.substr(ind,i+1-ind);
            if(set.find(str)!=set.end()){
                fun(i+1,s,set,subans+str+" ",ans);
            }
        }
    }
};
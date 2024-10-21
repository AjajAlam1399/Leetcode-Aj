class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>set;
        bool flag=false;
        return fun(0,s,set,flag);
    }

    int fun(int ind,string &s,unordered_set<string>&set,bool &flag){
        if(ind==s.size()){
            // flag=true;
            return 0;
        }
        int ans=0;
        for(int i=ind;i<s.size();i++){
            // if(flag){
            //     break;
            // }
            string str=s.substr(ind,i-ind+1);
            int cnt=0;
            if(set.find(str)==set.end()){
                set.insert(str);
                cnt=1+fun(i+1,s,set,flag);
                ans=max(ans,cnt);
                set.erase(str);
            }
        }
        return ans;
    }
};
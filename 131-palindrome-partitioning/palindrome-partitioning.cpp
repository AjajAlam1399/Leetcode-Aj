class Solution {
    vector<vector<string>>ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string>subans;

        fun(0,subans,s);

        return ans;
    }

    bool isvalid(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void fun(int i,vector<string>&subans,string &s){

        if(i==s.size()){
            return ;
        }
        if(isvalid(i,s.size()-1,s)){
            string str=s.substr(i,s.size()-i);
            subans.push_back(str);
            ans.push_back(subans);
            subans.pop_back();
        }
        for(int j=i;j<s.size();j++){
            if(isvalid(i,j,s)){
                string str=s.substr(i,j-i+1);
                subans.push_back(str);
                fun(j+1,subans,s);
                subans.pop_back();
            }
        }
    }
};
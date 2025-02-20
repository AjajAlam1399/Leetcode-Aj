class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>map;
        int n=nums.size();
        string str="";
        for(int i=0;i<n;i++){
            map[nums[i]]++;
            str.push_back('0');
        }
        cout<<str<<endl;
        string ans;
        fun(0,str,ans,map);
        return ans;
    }

    bool fun(int ind,string str,string &ans,unordered_map<string,int>&map){
        if(map.find(str)==map.end()){
            ans=str;
            return true;
        }
        if(ind==str.size()){
            return false;
        }
        str[ind]='1';
        if(fun(ind+1,str,ans,map)){
            return true;
        }
        str[ind]='0';
        return false;
    }
};
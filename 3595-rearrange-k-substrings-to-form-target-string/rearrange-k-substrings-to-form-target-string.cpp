class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string,int>map1;
        unordered_map<string,int>map2;
        int i=0,j=0,n=s.size();
        int lenStr=n/k;
        for(int l=0;l<k;l++){
            string str1="";
            string str2="";
            while(i<j+lenStr){
                str1.push_back(s[i]);
                str2.push_back(t[i]);
                i++;
            }
            map1[str1]++;
            map2[str2]++;
            j+=lenStr;
        }
        for(auto it : map1){
            if(it.second!=map2[it.first])return false;
        }
        return true;
    }
};
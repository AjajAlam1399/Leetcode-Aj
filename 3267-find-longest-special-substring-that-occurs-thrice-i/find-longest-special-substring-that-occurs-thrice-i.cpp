class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        int ans=-1;
        unordered_map<string,int>map;
        for(int i=0;i<n;i++){
            string str="";
            str.push_back(s[i]);
            map[str]++;
            for(int j=i+1;j<n;j++){
                if(str.back()==s[j]){
                    str.push_back(s[j]);
                }
                else{
                    break;
                }
                map[str]++;
            }
            
        }
        for(auto it :map){
                if(it.second>=3){
                    int len=it.first.size();
                    ans=max(ans,len);
                }
            }
        return ans;
    }
};
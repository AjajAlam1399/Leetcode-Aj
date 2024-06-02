class Solution {
public:
    int minimumChairs(string s) {
       int cnt=0;
       int ans=0;

       for(int i=0;i<s.size();i++){
        if(s[i]=='E')cnt++;
        else cnt--;
        ans=max(ans,cnt);
       } 
       return ans;
    }
};
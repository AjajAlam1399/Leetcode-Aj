class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        unordered_map<int,int>map;
        map[0]=-1;
        int mask=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                mask^=1;
            }
            else if(s[i]=='e'){
                mask^=2;
            }
            else if(s[i]=='i'){
                mask^=4;
            }
            else if(s[i]=='o'){
                mask^=8;
            }
            else if(s[i]=='u'){
                mask^=16;
            }
            if(map.find(mask)!=map.end()){
                ans=max(ans,i-map[mask]);
            }
            else{
                map[mask]=i;
            }
        }
        return ans;
    }
};
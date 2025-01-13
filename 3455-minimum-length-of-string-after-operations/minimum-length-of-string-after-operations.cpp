class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int>vec(26,0);
        for(int i=0;i<n;i++){
            vec[s[i]-'a']++;
        }
        int ans=n;

        for(int i=0;i<26;i++){
            while(vec[i]>2){
                ans-=2;
                vec[i]-=2;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int>first(26,-1);
        vector<int>last(26,-1);

        for(int i=0;i<s.size();i++){
            int ind=s[i]-'a';
            if(first[ind]==-1){
                first[ind]=i;
            }
        }

        for(int j=n-1;j>=0;j--){
            int ind=s[j]-'a';
            if(last[ind]==-1){
                last[ind]=j;
            }
        }

        int cnt=0;

        for(int i=0;i<26;i++){
           if(first[i]!=-1 && last[i]!=-1){
               int sind=first[i]+1;
               int eind=last[i]-1;
               unordered_map<char,int>map;
               while(sind<=eind){
                   map[s[sind]]++;
                   sind++;
               }
               cnt+=map.size();
           }
        }

        return cnt;
    }
};
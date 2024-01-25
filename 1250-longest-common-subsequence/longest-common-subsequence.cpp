class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int size1=s1.size();
        int size2=s2.size();
        
        vector<int>curr(size2+1,0);
        vector<int>prev(size2+1,0);
        
        // return fun(size1,size2,s1,s2,dp);
        
        for(int i=1;i<=size1;i++){
            for(int j=1;j<=size2;j++){
                if(s1[i-1]==s2[j-1]){
                     curr[j]= 1+prev[j-1];
                }
                else  curr[j]= max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        
        return curr[size2];
    }
};
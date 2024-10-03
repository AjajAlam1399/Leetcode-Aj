class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long num=0;
        int n=word.size();
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            long long currmod=num*10+word[i]-'0';
            num=currmod%m;
            if(num==0){
                ans[i]=1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        if(n==k)return 1;
        int cnt=1;
        int i=k;
        while(i<n){
            int j=0;
            int l=i;
            bool flag=false;
            while(l<n){
                if(word[j]==word[l]){
                    l++;
                    j++;
                }
                else{
                    flag=true;
                    break;
                }
            }
            if(!flag)return cnt;
            cnt++;
            i+=k;
        }
        return cnt;
    }
};
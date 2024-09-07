class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        if(n==k)return 1;

        vector<int>lps(n,0);
        int i=1,len=0;

        while(i<n){
            if(word[i]==word[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    i++;
                }
            }
        }
        int cnt=1;
        i=k;
        while(i<n){
            int rem=lps[n-1];
            int remlen=n-i;
            if(rem>=remlen){
                int j=i,p=0;
                bool flag=false;
                while(j<n){
                    if(word[j]==word[p]){
                        j++;
                        p++;
                    }
                    else{
                        flag=true;
                        break;
                    }
                }
                if(!flag)return cnt;

            }
            cnt++;
            i+=k;
        }
        return cnt;
    }
};
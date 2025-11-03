class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str=a;
        int cnt=1;
        while(str.size()<b.size()){
            str+=a;
            cnt++;
        }

        if(fun(str,b))return cnt;
        str+=a;
        if(fun(str,b))return cnt+1;
        return -1;
    }

    bool fun(string str ,string pattern){

        int n=pattern.size();
        vector<int>lps(n+1,0);

        int len=0,i=1;

        while(i<n){

            if(pattern[i]==pattern[len]){
                len++;
                lps[i++]=len;
            }
            else{
                if(len==0){
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }

        int j=0;
        i=0;
        int n1=str.size();
        int n2=pattern.size();

        while(i<n1){
            if(str[i]==pattern[j]){
                i++;
                j++;
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j=lps[j-1];
                }
            }
            if(j==n2){
                return true;
            }
        }

        return false;
    }
};
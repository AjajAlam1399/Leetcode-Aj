class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        string ans=s;

        int j=1,len=0;
        vector<int>lps(part.size());

        while(j<part.size()){
            if(part[j]==part[len]){
                lps[j++]=++len;
            }
            else{
                if(len==0){
                    j++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }

        while(true){
            string curr=ans;
            int i=0,n=curr.size();
            j=0;
            bool flag=false;
            while(i<n){
                if(curr[i]==part[j]){
                    i++;
                    j++;
                }
                else{
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
                if(j==part.size()){
                    flag=true;
                    break;
                }
            }
            if(flag){
                int len=part.size();
                ans=curr.substr(0,i-len);
                if(i<curr.size()){
                    ans+=curr.substr(i);
                }
            }
            else{
                break;
            }
        }
        return ans;
    }
};
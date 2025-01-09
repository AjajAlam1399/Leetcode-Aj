class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0,n=words.size();

        for(int i=0;i<n;i++){
            string str1=words[i];
            for(int j=i+1;j<n;j++){
                string str2=words[j];
                bool f1=true;
                bool f2=true;
                if(str1.size()>str2.size()){
                    continue;
                }
                int ind=0;
                while(ind<str1.size()){
                    if(str1[ind]!=str2[ind]){
                        f1=false;
                        break;
                    }
                    if(str1[str1.size()-1-ind]!=str2[str2.size()-1-ind]){
                        f2=false;
                        break;
                    }
                    ind++;
                }
                if(f1 && f2)cnt++;
            }
        }
        return cnt;
    }
};
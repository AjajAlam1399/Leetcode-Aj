class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        int cnt=0;
        vector<int>lower(26,0);
        vector<int>upper(26,0);

        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z'){
                lower[word[i]-'a']=i+1;
            }
            else{
                int ind=word[i]-'A';
                if(upper[ind]==0){
                    upper[ind]=i+1;
                }
            }
        }

        for(int i=0;i<26;i++){
            if(lower[i]!=0 && upper[i]!=0 && lower[i]<upper[i]){
                cnt++;
            }
        }

        return cnt;
    }
};
class Solution {
public:
    int countSubstrings(string s) 
    {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isValid(s,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    bool isValid(string st,int i,int j){

        while(j>i){
            if(st[i]!=st[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
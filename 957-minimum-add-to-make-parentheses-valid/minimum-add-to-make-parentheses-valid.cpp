class Solution {
public:
    int minAddToMakeValid(string s) {
        int op=0,co=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                op++;
            }
            else{
                if(op>0){
                    op--;
                }
                else{
                    co++;
                }
            }
        }
        return op+co;
    }
};
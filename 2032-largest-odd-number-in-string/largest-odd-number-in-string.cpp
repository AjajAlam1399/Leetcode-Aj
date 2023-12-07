class Solution {
public:
    string largestOddNumber(string num) {
        
        int n=num.size();
        bool flag=false;
        int ind;

        for(int i=n-1;i>=0;i--){
            int dig=num[i]-'0';
            if(dig%2!=0){
                flag=true;
                ind=i;
                break;
            }
        }

        return flag==false?"":num.substr(0,ind+1);

    }
};
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0,n1=version1.size(),n2=version2.size(),num1=0,num2=0;

        while(i<n1 || j<n2){
            while(i<n1 && version1[i]!='.'){
                num1*=10;
                num1+=version1[i]-'0';
                i++;
            }
            while(j<n2 && version2[j]!='.'){
                num2*=10;
                num2+=version2[j]-'0';
                j++;
            }
            if(num1<num2)return -1;
            if(num1>num2)return 1;
            num1=0,num2=0;
            i++;
            j++;
        }
        return 0;
    }
};
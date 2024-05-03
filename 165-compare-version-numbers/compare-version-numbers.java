class Solution {
    public int compareVersion(String version1, String version2) {
        int i=0,j=0,n1=version1.length(),n2=version2.length(),num1=0,num2=0;

        while(i<n1 || j<n2){
            while(i<n1 && version1.charAt(i)!='.'){
                num1*=10;
                num1+=version1.charAt(i)-'0';
                i++;
            }
            while(j<n2 && version2.charAt(j)!='.'){
                num2*=10;
                num2+=version2.charAt(j)-'0';
                j++;
            }
            if(num1<num2)return -1;
            if(num1>num2)return 1;
            num1=0;
            num2=0;
            i++;
            j++;
        }
        return 0;
    }
}
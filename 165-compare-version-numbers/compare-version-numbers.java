class Solution {
    public int compareVersion(String v1, String v2) {
        int n1=v1.length();
        int n2=v2.length();

        int  i=0;
        int j=0;

        int curr1=0;
        int curr2=0;

        while(i<n1 || j<n2){
            while(i<n1 && v1.charAt(i)!='.' ){
                curr1*=10;
                curr1+=v1.charAt(i)-'0';
                i++;
            }
             while(j<n2 && v2.charAt(j)!='.' ){
                curr2*=10;
                curr2+=v2.charAt(j)-'0';
                j++;
            }
            // cout<<curr1<<"-"<<curr2<<endl;
            if(curr1>curr2)return 1;
            else if(curr1<curr2) return -1;
            curr1=0;
            curr2=0;
            i++;
            j++;
        }
        return 0;
    }
}
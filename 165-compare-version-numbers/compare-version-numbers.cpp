class Solution {
    using ll=long long;
public:
    int compareVersion(string v1, string v2) {
        int n1=v1.size();
        int n2=v2.size();

        ll i=0,j=0;

        ll curr1=0,curr2=0;

        while(i<n1 || j<n2){
            while(i<n1 && v1[i]!='.' ){
                curr1*=10;
                curr1+=v1[i]-'0';
                i++;
            }
             while(j<n2 && v2[j]!='.' ){
                curr2*=10;
                curr2+=v2[j]-'0';
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
};
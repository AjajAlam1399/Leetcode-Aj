class Solution {
public:
    int numSteps(string s) {
      int n=s.size(),i=0;
      int cnt=0;
      while(i<n && s[i]=='0' ){
        i++;
      }  
      string ans="1";

      while(s!=ans){
        int len=s.size()-1;
        if(s[len]=='1'){
            s=add(s);
            cout<<s<<endl;
        }
        else{
            s.pop_back();
        }
        cnt++;
      }
      return cnt;
    }


    string add(string s){
        int n=s.size()-1;
        int carry=1;
        s[n]='0';
        n--;
        while(n>=0){
            int sum=s[n]-'0'+carry;
            if(sum==2){
                carry=1;
                s[n]='0';
            }
            else if(sum==1){
                carry=0;
                s[n]='1';
            }
            else{
                carry=0;
                s[n]='0';
            }
            n--;
        }
        if(carry){
            s.insert(s.begin(),'1');
        }
        return s;
    }
};
class Solution {
public:
    string decodeString(string s) {
        int n=s.size();

        stack<char>st;

        for(int i=0;i<n;i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                string str="";
                while(st.top()!='['){
                    str.push_back(st.top());
                    st.pop();
                }
                st.pop();
                string numstr="";
                while(!st.empty() && 
                st.top()>='0' && st.top()<='9'){
                    numstr.push_back(st.top());
                    st.pop();
                }
                int num=0;
                for(int j=numstr.size()-1;j>=0;j--){
                    num=num*10+(numstr[j]-'0');
                }
                // cout<<num<<","<<str<<endl;
                string pushStr="";
                for(int j=1;j<=num;j++){
                    pushStr+=str;
                }
                // cout<<pushStr<<endl;
                for(int j=pushStr.size()-1;j>=0;j--){
                    st.push(pushStr[j]);
                }
            }
        }
        string ans="";

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
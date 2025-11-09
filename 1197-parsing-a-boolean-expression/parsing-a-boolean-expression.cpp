class Solution {
public:
    bool parseBoolExpr(string exp) {

        stack<char> st;

        int n = exp.size();

        for (int i = 0; i < n; i++) {
            if (exp[i] == 't' || exp[i] == 'f' || exp[i] == '(' ||
                exp[i] == '&' || exp[i] == '!' || exp[i] == '|') {
                    // cout<<exp[i]<<i<<endl;
                st.push(exp[i]);
            } else if (exp[i] == ')') {
                int tcnt = 0;
                int fcnt = 0;

                while (!st.empty() && st.top() != '(') {
                    char ch = st.top();
                    st.pop();

                    if (ch == 't')
                        tcnt++;
                    else
                        fcnt++;
                }
                st.pop();

                int op = st.top();
                st.pop();
                char ans;

                if (op == '|') {
                    ans = tcnt ? 't' : 'f';
                } else if (op == '&') {
                    ans = fcnt != 0 ? 'f' : 't';
                } else {
                    ans = tcnt ? 'f' : 't';
                }

                st.push(ans);
            }
        }

        return st.top()=='t'?true:false;
    }
};

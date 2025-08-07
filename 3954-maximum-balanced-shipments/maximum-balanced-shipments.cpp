class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {

        int n = weight.size();

        stack<int> st;
        vector<int> vec(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&  weight[i]>=weight[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                vec[i] = st.top();
            }
            st.push(i);
        }
        int ans=0;
        int prev=-1;
        int start=0;

        for(int i=0;i<n;i++){
            if(vec[i]!=-1){
                if(prev!=vec[i] && start<i && vec[i]>=start){
                    ans++;
                    prev=vec[i];
                    start=i+1;
                }
            }
        }

        return ans;
    }
};
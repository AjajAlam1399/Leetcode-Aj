class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int>st;

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && prices[st.top()]>=prices[i]){
                auto el=st.top();
                st.pop();
                ans[el]=prices[el]-prices[i];
            }
            st.push(i);
        }
        while(!st.empty()){
            ans[st.top()]=prices[st.top()];
            st.pop();
        }
        return ans;
    }
};
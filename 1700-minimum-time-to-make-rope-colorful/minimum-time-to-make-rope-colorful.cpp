class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        stack<pair<char,int>>st;
        int ans=0;

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({colors[i],neededTime[i]});
            }
            else{
                if(st.top().first==colors[i]){
                    if(st.top().second<=neededTime[i]){
                        cout<<st.top().second<<endl;
                        ans+=st.top().second;
                        st.pop();
                        st.push({colors[i],neededTime[i]});
                    }
                    else{
                        ans+=neededTime[i];
                        cout<<neededTime[i]<<endl;
                    }
                }
                else{
                    st.push({colors[i],neededTime[i]});
                }
            }
        }
        return ans;
    }
};
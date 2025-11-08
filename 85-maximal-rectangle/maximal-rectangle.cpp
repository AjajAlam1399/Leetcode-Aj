class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>vec(m,0);

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    vec[j]+=1;
                }
                else{
                    vec[j]=0;
                }
            
            }

            int currAns=fun(vec);
            ans=max(ans,currAns);
        }

        return ans;
    }

    int fun(vector<int>&vec){
        int ans=0;

        stack<int>st;
        int n=vec.size();

        for(int i=0;i<=n;i++){

            while(!st.empty() && (i==n || vec[st.top()]>=vec[i])){
                int ind=st.top();
                 int br=vec[ind];
                st.pop();
                int len;

                if(!st.empty()){
                    len=i-st.top()-1;
                }
                else{
                    len=i;
                }
                ans=max(ans,br*len);
            }
            st.push(i);
        }

        return ans;
    }
};
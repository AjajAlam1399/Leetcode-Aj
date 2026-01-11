class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n=matrix.size(),m=matrix[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            vector<int>vec(m,0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++){
                    if(matrix[j][k]=='1'){
                        vec[k]++;
                    }
                    else{
                        vec[k]=0;
                    }
                }
                ans=max(ans,fun(vec));
            }
        }

        return ans;
        
    }

    int fun(vector<int>&vec){

        stack<int>st;
        int ans=0;

        for(int i=0;i<=vec.size();i++){
            while(!st.empty() && (i==vec.size() || vec[i]<vec[st.top()])){
                int len = vec[st.top()];
                st.pop();
                int w;
                if(!st.empty()){
                    w=i-st.top()-1;
                }
                else{
                    w=i;
                }
                ans=max(ans,w*len);

            }

            st.push(i);
        }

        return ans;
    }
};
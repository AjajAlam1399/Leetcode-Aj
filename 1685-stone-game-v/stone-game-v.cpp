class Solution {
    int dp[505][5005];
public:
    int stoneGameV(vector<int>& stoneValue) {

        memset(dp,-1,sizeof(dp));
        
        int n=stoneValue.size();
        vector<int>sum(n,0);
        sum[0]=stoneValue[0];

        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+stoneValue[i];
        }

        return fun(0,n-1,sum,stoneValue);
    }

    int fun(int i,int j,vector<int>&sum , vector<int>&arr){

        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=i;k<j;k++){
            int left=sum[k]-sum[i]+arr[i];
            int right=sum[j]-sum[k];

            if(left<right){
                ans=max(ans,left+fun(i,k,sum,arr));
            }
            else if(left>right){
                ans=max(ans,right+fun(k+1,j,sum,arr));
            }
            else{
                ans=max(ans,max(left+fun(i,k,sum,arr),right+fun(k+1,j,sum,arr)));
            }
        }
        return dp[i][j]=ans;
    }
};
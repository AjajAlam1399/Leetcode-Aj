class Solution {
    const int N=2*1e5+1;
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int pos, int k) {
        vector<int>vec(N,0);

        for(auto it : fruits){
            vec[it[0]]=it[1];
        }

        vector<int>left(N);
        vector<int>right(N);

        for(int i=pos+1;i<N;i++){
            right[i]=vec[i]+right[i-1];
        }

        for(int i=pos-1;i>=0;i--){
            left[i]=vec[i]+left[i+1];
        }

        int ans=0;


        for(int p=0;p<=k;p++){

            int l=left[max(0,pos-p)];
            int rem=k-2*p;

            if(rem>=0 && rem<=k){
                l+=right[min(N-1,pos+rem)];
            }
            ans=max(ans,l+vec[pos]);

            int r=right[min(N-1,pos+p)];
            
            if(rem>=0 && rem<=k){
                r+=left[max(0,pos-rem)];
            }
            ans=max(ans,r+vec[pos]);
        }

        return ans;
    }
};
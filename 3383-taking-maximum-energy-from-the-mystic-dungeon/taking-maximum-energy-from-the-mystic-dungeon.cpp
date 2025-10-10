class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();

        vector<int>leftDp(n);
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            if(i-k>=0){
                leftDp[i]=leftDp[i-k]+energy[i];
            }
            else{
                leftDp[i]=energy[i];
            }

            if(i+k>=n){
                ans=max(ans,energy[i]);
                ans=max(ans,leftDp[i]);
            }
        }

        vector<int>rightDp(n);

        for(int i=n-1;i>=0;i--){
            if(i+k>=n){
                rightDp[i]=energy[i];
            }
            else{
                rightDp[i]=energy[i]+rightDp[i+k];
            }
            ans=max(ans,rightDp[i]);
        }

        return ans;
    }
};
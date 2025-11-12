class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n=nums.size();

        int m=INT_MAX;

        int oneCnt=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1)oneCnt++;
            int gcd=nums[i];
            if(gcd==1){
                m=0;
                continue;
            }
            int cnt=0;
            bool flag=false;
            for(int j=i+1;j<n;j++){
                cnt++;
                gcd=__gcd(gcd,nums[j]);
                if(gcd==1){
                    flag=true;
                    break;
                }
            }

            if(flag){
                m=min(m,cnt);
            }
        }

        cout<<m<<endl;

        if(m==INT_MAX)return -1;

        if(m==0)return n-oneCnt;
        return m+n-1;

    }
};
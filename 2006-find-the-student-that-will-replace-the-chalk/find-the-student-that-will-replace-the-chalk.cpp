class Solution {
    using ll=long long;
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum=0;
        

        int n=chalk.size();
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=chalk[i];
        }
        ll rem=k%sum;
        for(int i=0;i<n;i++){
            if(rem<chalk[i]){
                ans=i;
                break;
            }
            rem-=chalk[i];
        }
        return ans;
    }
};
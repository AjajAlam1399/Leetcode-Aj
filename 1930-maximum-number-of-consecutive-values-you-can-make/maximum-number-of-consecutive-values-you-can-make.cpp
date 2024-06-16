class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        long long sum=0;
        int ind=0,n=coins.size();

        while(ind<n){
            if(coins[ind]<=sum+1){
                sum+=coins[ind++];
            }
            else{
                break;
            }
        }
        return sum+1;
    }
};
class Solution {
    using ll=long long ;
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll n=differences.size();
        ll maxVal=INT_MIN;
        ll minVal=INT_MAX;
        ll sum=0;
        for(auto num:differences){
            sum+=num;
            maxVal=max(maxVal,sum);
            minVal=min(minVal,sum);
        }
        int ans=0;

        for(ll i=lower;i<=upper;i++){
            if(i+minVal>=lower && i+maxVal<=upper){
                ans++;
            }
        }

        return ans;
    }
};
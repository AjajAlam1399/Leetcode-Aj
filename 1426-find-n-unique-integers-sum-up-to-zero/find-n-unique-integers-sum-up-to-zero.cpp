class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;

        int sum=0;

        for(int i=1;i<n;i++){
            sum+=i;
            ans.push_back(i);
        }
        ans.push_back(-1*sum);
        return ans;
    }
};
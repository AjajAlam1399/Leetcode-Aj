class Solution {
public:
    int minMoves(vector<int>& a, int limit) {
        
        int n = a.size();
        vector<int> LineSweep(2e5, 0);
        vector<int> sum(2e5, 0);
        for(int i = 0; i < n/2; i++){
            int mn = min(a[i], a[n - 1 - i]) + 1;
            int mx = max(a[i], a[n - 1 - i]) + limit;
            LineSweep[mx + 1]--;
            LineSweep[mn]++;
            sum[a[i] + a[n - 1 - i]]++;
        }
        for(int i = 1; i < 2e5; i++) {
            LineSweep[i] += LineSweep[i - 1];
        }
        int res = n;
        for(int possibleSum = 2; possibleSum < 2e5; possibleSum++){
            res = min(res, n - LineSweep[possibleSum] - sum[possibleSum]);
        }
        return res;
    }
};
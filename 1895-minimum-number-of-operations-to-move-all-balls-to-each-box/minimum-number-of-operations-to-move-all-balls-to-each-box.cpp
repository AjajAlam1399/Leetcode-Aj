class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n);
        int sum=0,cnt=0;

        for(int i=0;i<n;i++){
            sum+=cnt;
            if(boxes[i]=='1')cnt++;
            ans[i]+=sum;
        } 
        sum=0,cnt=0;
        for(int i=n-1;i>=0;i--){
            sum+=cnt;
            if(boxes[i]=='1')cnt++;
            ans[i]+=sum;
        }
        return ans;
    }
};
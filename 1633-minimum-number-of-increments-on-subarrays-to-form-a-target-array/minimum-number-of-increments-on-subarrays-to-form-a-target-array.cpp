class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int left=target[0];
        int curr=left;

        for(int i=1;i<n;i++){
            if(target[i]>curr){
                left+=target[i]-curr;
            }
            curr=target[i];
        }

        int right=target[n-1];
        curr=right;

        for(int i=n-1;i>=0;i--){
            if(target[i]>curr){
                right+=target[i]-curr;
            }
            curr=target[i];
        }

        return min(left,right);
    }
};
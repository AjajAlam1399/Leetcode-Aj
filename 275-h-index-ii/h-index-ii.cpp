class Solution {
public:
    bool possible(int &h,vector<int>& citations){
        int cnt = 0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=h) cnt++;
        }
        if(cnt>=h) return true;
        return false;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low = 0, high =citations[n-1];
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(mid,citations)){
                ans=mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};
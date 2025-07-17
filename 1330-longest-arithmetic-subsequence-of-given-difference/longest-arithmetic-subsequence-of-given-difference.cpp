class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int>map;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            map[arr[i]]=max(map[arr[i]],map[arr[i]-diff]+1);
            ans=max(ans,map[arr[i]]);
        }
        return ans;
    }
};
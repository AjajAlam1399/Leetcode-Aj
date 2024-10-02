class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);

        vector<vector<int>>vec;

        for(int i=0;i<arr.size();i++){
            vec.push_back({arr[i],i});
        }

        sort(vec.begin(),vec.end());
        int cnt=1;
        for(int i=0;i<n;i++){
            if(i==0){
                ans[vec[i][1]]=cnt;
            }
            else{
                if(vec[i-1][0]!=vec[i][0]){
                    cnt++;
                }
                ans[vec[i][1]]=cnt;
            }
        }

        return ans;
    }
};
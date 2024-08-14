class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>vec;

        sort(nums.begin(),nums.end());


        for(int i=0;i<n;i++){
            vector<int>cvec;
            for(int j=i+1;j<n;j++){
                int diff=abs(nums[i]-nums[j]);
                cvec.push_back(diff);
            }
            vec.push_back(cvec);
        }

        int s=0,e=nums[n-1]-nums[0];

        

        while(s<e){
            int mid=(s+e)/2;
            int cnt=fun(vec, mid);
            if(cnt<k)s=mid+1;
            else e=mid;
        }  

        return s;
    }

    int fun(vector<vector<int>>&vec,int mid){
        int cnt=0;

        for(int i=0;i<vec.size();i++){
            cnt+=upper_bound(vec[i].begin(),vec[i].end(),mid)-vec[i].begin();
        }
        

        return cnt;
    }
};
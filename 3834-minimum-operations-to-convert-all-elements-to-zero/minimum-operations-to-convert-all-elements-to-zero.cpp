class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n=nums.size();

        stack<int>st;
        vector<int>right(n,n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }

        unordered_map<int,vector<int>>map;

        for(int i=0;i<n;i++){
            map[nums[i]].push_back(i);
        }

        int ans=0;

        for(auto it : map){
            if(it.first==0)continue;
            vector<int>vec=it.second;
            int curr=1;
            int last=vec.back();
            for(int  i=vec.size()-2;i>=0;i--){
                if(right[vec[i]]<last){
                    curr++;
                }
                last=min(last,vec[i]);
            }
            ans+=curr;
        }

        return ans;
    }
};
class Solution {
    int ans;
    vector<vector<int>>graph;
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        int total=0;

        for(int i=0;i<n;i++){
            total^=nums[i];
        }

        graph.resize(n);

        for(auto it :edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        ans=INT_MAX;
        vector<int>arr(n,0);
        fun(0,-1,total,nums,arr);
        return ans;
    }

    void fun(int node,int parent,int total,vector<int>&nums,vector<int>&arr){
        arr[node]^=nums[node];

        for(auto adjnode:graph[node]){
            if(adjnode==parent)continue;
            fun(adjnode,node,total,nums,arr);
            int rem=total^arr[adjnode];
            vector<int>vec(nums.size(),0);
            fun2(node,adjnode,arr[adjnode],rem,vec,nums);
            arr[node]^=arr[adjnode];
        }
    }

    void fun2(int node,int par,int com1,int rem,vector<int>&arr,vector<int>&nums){
        arr[node]^=nums[node];

        for(auto adjnode:graph[node]){
            if(adjnode==par)continue;
            fun2(adjnode,node,com1,rem,arr,nums);
                int com2=arr[adjnode];
                int com3=rem^com2;
                int maxVal=max(com1,max(com2,com3));
                int minVal=min(com1,min(com2,com3));
                ans=min(ans,maxVal-minVal);
                arr[node]^=arr[adjnode];
        }
    }
};
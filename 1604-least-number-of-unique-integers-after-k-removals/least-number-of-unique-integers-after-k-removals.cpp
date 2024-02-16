class Solution {
    using pp=pair<int,int>;
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }

        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(auto it:map){
            pq.push({it.second,it.second});
        }
        while(k>0){
            auto it=pq.top();
            pq.pop();
            if(k>=it.first){
                k-=it.first;
            }
            else{
                k=0;
                pq.push({it.first-k,it.second});
            }
        }
        return pq.size();
    }
};
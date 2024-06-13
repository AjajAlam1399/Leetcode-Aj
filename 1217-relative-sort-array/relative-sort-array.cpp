class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>map;

        for(int i=0;i<arr1.size();i++){
            map[arr1[i]]++;
        }
        vector<int>ans;

        for(int i=0;i<arr2.size();i++){
            int cnt=map[arr2[i]];
            for(int j=1;j<=cnt;j++)ans.push_back(arr2[i]);
            map.erase(arr2[i]);
        }
        for(auto it:map){
            for(int i=0;i<it.second;i++)ans.push_back(it.first);
        }

        return ans;
    }
};
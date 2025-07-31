class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {

        unordered_set<int>ans;
        unordered_set<int>prev;

        prev.insert(0);

        for(int i=0;i<arr.size();i++){
            unordered_set<int>curr;
            for(auto it :prev ){
                curr.insert(it|arr[i]);
            }
            curr.insert(arr[i]);
            prev=curr;
            ans.insert(curr.begin(),curr.end());
        }

        return ans.size();
    }
};
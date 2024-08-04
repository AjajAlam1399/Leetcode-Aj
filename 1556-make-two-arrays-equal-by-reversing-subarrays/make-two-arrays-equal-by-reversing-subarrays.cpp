class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        vector<int>vec1(1001);
        vector<int>vec2(1001);

        for(int i=0;i<n;i++){
            vec1[target[i]]++;
            vec2[arr[i]]++;
        }

        for(int i=0;i<=1000;i++){
            if(vec1[i]!=vec2[i])return false;
        }
        return true;
    }
};
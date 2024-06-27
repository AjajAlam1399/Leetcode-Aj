class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int val1,val2;
        val1=edges[0][0];
        val2=edges[0][1]; 
        if(val1==edges[1][0] || val1==edges[1][1])return val1;
        return val2;
    }
};
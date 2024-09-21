class Solution {
    static bool cmp(int a,int b){
        string str1=to_string(a);
        string str2=to_string(b);
        return str1<str2;
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};
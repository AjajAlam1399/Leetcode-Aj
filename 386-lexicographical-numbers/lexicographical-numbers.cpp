class cmp{
    public:
    bool operator()(string a,string b){
        return a>b;
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        priority_queue<string,vector<string>,cmp>pq;

        for(int i=1;i<=n;i++){
            pq.push(to_string(i));
        }

        while(!pq.empty()){
            ans.push_back(stoi(pq.top()));
            pq.pop();
        }
        return ans;
    }
};
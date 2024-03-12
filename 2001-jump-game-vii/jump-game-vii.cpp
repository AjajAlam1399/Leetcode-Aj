class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        queue<int>q;
        q.push(0);
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                while(!q.empty() && q.front()<i-maxJump){
                    q.pop();
                }
                if(q.empty()){
                    return false;
                }
                int prev=q.front();
                // q.pop();
                if(i>=prev+minJump && i<=prev+maxJump){
                    q.push(i);
                    if(i==n-1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
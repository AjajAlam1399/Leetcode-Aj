class Solution {
    using ll=long long;
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        unordered_map<int,int>visted;
        ll ans=0;
        int i=0,n=instructions.size();

        while(i>=0 && i<n){
            if(visted.find(i)!=visted.end()){
                break;
            }
            visted[i]=1;
            if(instructions[i]=="add"){
                ans+=values[i];
                i++;
            }
            else{
                i+=values[i];
            }
        }
        return ans;
    }
};
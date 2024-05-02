class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int score=0;
        int ans=0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                ans=max(ans,score);
                i++;
            }
            else if(score){
                score--;
                power+=tokens[j];
                j--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
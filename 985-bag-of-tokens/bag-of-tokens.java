class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int n=tokens.length,i=0,j=n-1;
        int ans=0,score=0;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power-=tokens[i];
                i++;
            }
            else if(score>=1){
                score--;
                power+=tokens[j];
                j--;
            }
            else{
                break;
            }
            ans=Math.max(ans,score);
        }
        return ans;
    }
}
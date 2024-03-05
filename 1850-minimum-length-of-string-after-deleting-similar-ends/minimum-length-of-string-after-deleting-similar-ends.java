class Solution {
    public int minimumLength(String s) {
        int n=s.length();
        int ans=n;
        int i=0,j=n-1;

        while(true){
            if(i>=j){
                break;
            }
            while(i+1<j && s.charAt(i)==s.charAt(i+1)){
                i++;
            }
            while(j-1>i && s.charAt(j)==s.charAt(j-1) ){
                j--;
            }
            if(s.charAt(i)==s.charAt(j)){
                ans=Math.min(ans,j-i-1);
                i++;
                j--;
            }
            else{
                break;
            }
        }

        return ans;
    }
}
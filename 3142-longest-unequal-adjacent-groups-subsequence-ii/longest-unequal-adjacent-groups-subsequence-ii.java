class Solution {
    public List<String> getWordsInLongestSubsequence(String[] words, int[] groups) {
        int n=words.length;
        int []dp=new int[n];
        Arrays.fill(dp,1);
        int []pos=new int[n];
        int maxsize=0;
        int lastind=-1;

        for(int i=0;i<n;i++){
            pos[i]=i;
            for(int j=0;j<i;j++){
                if(groups[i]!=groups[j] && words[i].length()==words[j].length()&&
                isvalid(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    pos[i]=j;
                }
            }
            if(dp[i]>maxsize){
                maxsize=dp[i];
                lastind=i;
            }
        }
        
        List<String>ans=new ArrayList<>(Collections.nCopies(maxsize,"123"));
        int ind=maxsize-1;
        while(lastind!=pos[lastind]){
            ans.set(ind,words[lastind]);
            ind--;
            lastind=pos[lastind];
        }
        ans.set(ind,words[lastind]);
        return ans;
    }
    boolean isvalid(String str1,String str2){
        int cnt=0;
        for(int i=0;i<str1.length();i++){
            if(str1.charAt(i)!=str2.charAt(i)){
                cnt++;
            }
            if(cnt>=2){
                return false;
            }
        }
        return cnt==1?true:false;
    }
}
class Solution {
    public int countPalindromicSubsequence(String s) {
        int n=s.length();
       int first[]=new int[26];
       Arrays.fill(first,-1);
       int last[]=new int[26];
       Arrays.fill(last,-1);

        for(int i=0;i<n;i++){
            int ind=s.charAt(i)-'a';
            if(first[ind]==-1){
                first[ind]=i;
            }
        }

        for(int j=n-1;j>=0;j--){
            int ind=s.charAt(j)-'a';
            if(last[ind]==-1){
                last[ind]=j;
            }
        }

        int cnt=0;

        for(int i=0;i<26;i++){
           if(first[i]!=-1 && last[i]!=-1){
               int sind=first[i]+1;
               int eind=last[i]-1;
               HashMap<Character,Integer>map=new HashMap<>();
               while(sind<=eind){
                   if(!map.containsKey(s.charAt(sind))){
                       map.put(s.charAt(sind),1);
                   }
                   sind++;
               }
               cnt+=map.size();
           }
        }

        return cnt;
    }
}
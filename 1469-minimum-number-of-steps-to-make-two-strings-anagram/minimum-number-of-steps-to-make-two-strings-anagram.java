class Solution {
    public int minSteps(String s, String t) {
        int vec1[]=new int[26];
        int vec2[]=new int[26];
        Arrays.fill(vec1,0);
        Arrays.fill(vec2,0);
        int n=s.length();

        int ans=0;

        for(int i=0;i<n;i++){
            vec1[s.charAt(i)-'a']++;
            vec2[t.charAt(i)-'a']++;
        }
        for(int i=0;i<26;i++){
            if(vec2[i]>vec1[i]){
                ans+=vec2[i]-vec1[i];
            }
        }

        return ans;
    }
}
class Solution {
    public boolean isAnagram(String s, String t) {
        int []arr1=new int[26];
        Arrays.fill(arr1,0);
        int []arr2=new int[26];
        Arrays.fill(arr2,0);

        for(int i=0;i<s.length();i++){
            int ind=s.charAt(i)-'a';
            arr1[ind]++;
        }
        for(int i=0;i<t.length();i++){
            int ind=t.charAt(i)-'a';
            arr2[ind]++;
        }
        boolean ans=true;

        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                ans=false;
                break;
            }
        }

        return ans;
    }
}
class Solution {
    public String compressedString(String word) {
        int n=word.length();
        int s=0;
        StringBuilder sb=new StringBuilder();

        while(s<n){
            char ch=word.charAt(s);
            int cnt=1;
            while(cnt<9 && s+1<n && word.charAt(s)==word.charAt(s+1)){
                cnt++;
                s++;
            }
            String str=String.valueOf(cnt);
            sb.append(str);
            sb.append(ch);
            s++;
        }
        return sb.toString();
    }
}
class Solution {
    public int countCharacters(String[] words, String chars) {
                
                int[] ch=new int[26];
                Arrays.fill(ch,0);

        for(int i=0;i<chars.length();i++){
            ch[chars.charAt(i)-'a']++;
        }

        int ans=0;

        for(int i=0;i<words.length;i++){
            String str=words[i];
            boolean flag=false;
            int[] vec=new int[26];
            for(int j=0;j<str.length();j++){
                vec[str.charAt(j)-'a']++;
            }
            for(int k=0;k<26;k++){
                if(vec[k]>ch[k]){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ans+=str.length();
            }
        }

        return ans;
    }
}
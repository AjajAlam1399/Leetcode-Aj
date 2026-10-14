class Solution {
    public String shortestPalindrome(String s) {

        StringBuilder str = new StringBuilder(s);
        str.append('#');
        for(int s_ind = s.length()-1;s_ind>=0 ;s_ind--){
            str.append(s.charAt(s_ind));
        }
        
        int str_len = str.length();

        int lps_arr [] = new int [str_len];
        Arrays.fill(lps_arr,0);
        int len=0;

        int str_ind=1;

        while(str_ind<str_len){

            if(str.charAt(str_ind)==str.charAt(len)){
                len++;
                lps_arr[str_ind]=len;
                str_ind++;
            }
            else{
                if(len==0){
                    str_ind++;
                }
                else{
                    len = lps_arr[len-1];
                }
            }
        }

        StringBuilder ans = new StringBuilder();
        int pref_len =s.length() -  lps_arr[str.length()-1];
        for(int s_ind=s.length()-1;s_ind>=0 && pref_len>0 ; s_ind--,pref_len--){
            ans.append(s.charAt(s_ind));
        }

        for(int s_ind=0; s_ind<s.length() ; s_ind++){
            ans.append(s.charAt(s_ind));
        }

        return ans.toString();
    }
}
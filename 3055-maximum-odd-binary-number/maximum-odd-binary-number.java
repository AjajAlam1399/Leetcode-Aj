class Solution {
    public String maximumOddBinaryNumber(String s) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='1'){
                cnt++;
            }
        }
        StringBuilder sb=new StringBuilder();
        while(cnt>1){
            sb.append('1');
            cnt--;
        }
        int size=sb.length();
        for(int i=0;i<s.length()-size-1;i++){
            sb.append('0');
        }
        sb.append('1');
        return sb.toString();
    }
}
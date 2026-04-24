class Solution {
    public String countAndSay(int n) {
        StringBuilder str = new StringBuilder("1");

        for(int i=2;i<=n;i++){
            int strLen = str.length();
            int ind=0;
            StringBuilder currStr = new StringBuilder();
            while(ind<strLen){
                int cnt=1;
                char ch = str.charAt(ind);
                ind++;
                while(ind<strLen && ch == str.charAt(ind)){
                    cnt++;
                    ind++;
                }
                currStr.append(String.valueOf(cnt));
                currStr.append(String.valueOf(ch));

            }
            str = currStr;
        }
        return str.toString();
    }
}
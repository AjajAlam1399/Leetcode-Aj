class Solution {
    public int minFlips(String s) {

        int zans = fun(s, 0);
        int oans = fun(s, 1);

        return Math.min(zans, oans);

    }

    int fun(String str,int start){

        StringBuilder  orgStr = new StringBuilder(str+str);
        StringBuilder flipStr = new StringBuilder(str+str);

        int curr=start;
        int cnt=0;
        int ans=Integer.MAX_VALUE;

        int s=0,e=0,n=orgStr.length();

        while(e<n){
            int indVa=orgStr.charAt(e)-'0';
            if(curr!=indVa){
                cnt++;
                flipStr.setCharAt(e,curr==0?'0':'1');
            }
            curr=curr==0?1:0;
            if(e-s+1 == n/2){
                ans=Math.min(ans,cnt);
                if(orgStr.charAt(s)!=flipStr.charAt(s)){
                    cnt--;
                }
                s++;
            }
            e++;
        }
        return ans;
    }
}
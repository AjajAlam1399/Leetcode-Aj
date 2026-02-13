class Solution {
    public int longestBalanced(String s) {
        int ans=1;
        int n=s.length();

        for(int i=0;i<n;i++){
            Map<Character,Integer>map = new HashMap<>();
            for(int j=i;j<n;j++){
                map.compute(s.charAt(j),(id,val)->{
                    if(val==null)return 1;
                    return val+1;
                });
                int val = map.get(s.charAt(j));
                boolean flag =true;
                for(Map.Entry<Character,Integer>entry : map.entrySet()){
                    if(entry.getValue()!=val){
                        flag=false;
                        break;
                    }
                }

                if(flag){
                    ans=Math.max(ans, j-i+1);
                }

            }
        }

        return ans;
    }
}
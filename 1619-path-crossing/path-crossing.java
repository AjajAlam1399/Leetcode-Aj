class Solution {
    public boolean isPathCrossing(String path) {
        Map<String,Integer>map=new HashMap<>();
        int n=path.length();
        int u=0;
        int l=0;
        String str=Integer.toString(u)+"#"+Integer.toString(l);
        map.put(str,1);

        for(int i=0;i<n;i++){
            if(path.charAt(i)=='N')u++;
            else if(path.charAt(i)=='S')u--;
            else if(path.charAt(i)=='E')l++;
            else{
                l--;
            }
             str=Integer.toString(u)+"#"+Integer.toString(l);
            if(map.containsKey(str)){
                return true;
            }
            else{
                map.put(str,1);
            }
        }

        return false;
    }
}
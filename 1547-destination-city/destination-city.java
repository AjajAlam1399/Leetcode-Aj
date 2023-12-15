class Solution {
    public String destCity(List<List<String>> paths) {
        Map<String,Integer>set=new HashMap<>();
         Map<String,Integer>map=new HashMap<>();

        for(List<String> it : paths){
            String v1=it.get(0);
            String v2=it.get(1);
            if(map.containsKey(v1)==false){
                map.put(v1,1);
            }
            if(set.containsKey(v1)==false){
                set.put(v1,1);
            }
            if(set.containsKey(v2)==false){
                 set.put(v2,1);
            }
        }
        String ans="";
        for(Map.Entry<String,Integer>it:set.entrySet()){
            if(map.containsKey(it.getKey())==false){
                ans=it.getKey();
                break;
            }
        }
        return ans;
    }
}
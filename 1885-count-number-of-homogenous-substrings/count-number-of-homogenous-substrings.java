class Solution {
    int mod=1000000000+7;
    public int countHomogenous(String s) {
        int i=-1,j=-1;
       int n=s.length();
       int ans=0;

       HashMap<Character,Integer>map=new HashMap<>();

       while(true){

           boolean f1=false;
           boolean f2=false;

           while(i<n-1){
               f1=true;
               i++;
               if(map.containsKey(s.charAt(i))){
                   map.replace(s.charAt(i),map.get(s.charAt(i))+1);
               }
               else{
                   map.put(s.charAt(i),1);
               }
               if(map.size()>1){
                   map.remove(s.charAt(i));
                   i--;
                   break;
               }
           }

           while(j<i){
               f2=true;
               if(map.size()==1){
                ans=(ans%mod+(i-j)%mod)%mod;
               }
               j++;
               if(map.containsKey(s.charAt(j)) && map.get(s.charAt(j))==1){
                   map.remove(s.charAt(j));
               }
               else{
                   map.replace(s.charAt(j),map.get(s.charAt(j))-1);
               }
               if(map.size()<1){
                    break;
               }
           }

           if(!f1 && !f2){
               break;
           }
       }
       
       return ans;
    }
}
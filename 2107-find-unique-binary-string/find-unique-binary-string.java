class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder sb = new StringBuilder();
        Map<String,Integer> map = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            map.put(nums[i],i);
        }
        return fun(0,sb,map,n);
    }

    String fun(int ind,StringBuilder subAns, Map<String,Integer>map,int n){

        if(ind==n){
            if(!map.containsKey(subAns.toString())){
                return subAns.toString();
            }
            return "";
        }

        String str1 = fun(ind+1,subAns.append('0'),map,n);
        if(!str1.equals("")){
            return str1;
        }
        subAns.deleteCharAt(subAns.length()-1);
        String str2 = fun(ind+1,subAns.append('1'),map,n);
        if(!str2.equals("")){
            return str2;
        }
        subAns.deleteCharAt(subAns.length()-1);
        return "";
    }
}
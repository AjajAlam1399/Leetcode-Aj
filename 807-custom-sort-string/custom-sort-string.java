class Solution {
    public String customSortString(String order, String s) {
        int arr[]=new int[26];
        Arrays.fill(arr,0);

        for(int i=0;i<s.length();i++){
            arr[s.charAt(i)-'a']++;
        }
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<order.length();i++){
            int ind=order.charAt(i)-'a';
            for(int j=0;j<arr[ind];j++){
                sb.append((char)('a'+ind));
            }
            arr[ind]=0;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                for(int j=0;j<arr[i];j++){
                    sb.append((char)('a'+i));
                }
            }
        }
        return sb.toString();
    }
}
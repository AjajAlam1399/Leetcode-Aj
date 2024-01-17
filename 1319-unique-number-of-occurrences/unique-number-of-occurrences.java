class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Arrays.sort(arr);
        int n=arr.length;
        int ind=0;
        int cnt1=1;
        Map<Integer,Integer>map=new HashMap<>();
        while(ind<n){
            while(ind+1<n && arr[ind]==arr[ind+1]){
                ind++;
                cnt1++;
            }
            ind++;
            if(map.containsKey(cnt1)){
                return false;
            }
            else{
                map.put(cnt1,1);
            }
            cnt1=1;
        }
        return true;
    }
}
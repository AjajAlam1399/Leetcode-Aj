class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n=temp.length;
        int ans []=new int[n];
        Arrays.fill(ans,0);
        Stack<Integer>st=new Stack<>();
        for(int i=n-1;i>=0;i--){
            while(st.empty()==false && temp[st.peek()]<=temp[i]){
                st.pop();
            }
            if(st.empty()==false){
                ans[i]=st.peek()-i;
            }
            st.push(i);
        }

        return ans;
    }
}
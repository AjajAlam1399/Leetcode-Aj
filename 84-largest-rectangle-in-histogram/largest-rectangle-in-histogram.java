class Solution {
    public int largestRectangleArea(int[] heights) {
        
        int n = heights.length;
        Stack<Integer>st = new Stack<>();
        int ans=0;

        for(int i=0;i<=n;i++){
            while(!st.isEmpty() && (i==n || heights[st.peek()]>heights[i])){
                int l = heights[st.pop()];
                int b;

                if(st.isEmpty()){
                    b=i;
                }
                else{
                    b=i-st.peek()-1;
                }
                ans = Math.max(ans,l*b);
            }
            st.push(i);
        }

        return ans;
    }
}
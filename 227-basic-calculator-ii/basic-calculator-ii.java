class Solution {
    public int calculate(String str) {
        StringBuilder s = new StringBuilder();

        for (int j = 0; j < str.length(); j++) {
            if (str.charAt(j) == ' ')
                continue;
            s.append(str.charAt(j));
        }
        int n = s.length();
        char sign = '+';

        Stack<Integer> st = new Stack<>();

        int i = 0;

        while (i < n) {
            int ind = i;
            int currNum = 0;
            while (ind < n && s.charAt(ind) >= '0' && s.charAt(ind) <= '9') {
                currNum *= 10;
                currNum += s.charAt(ind) - '0';
                ind++;
            }
            if (sign == '*' || sign == '/') {
                int prevNum = st.pop();
                currNum = sign == '*' ? currNum * prevNum : prevNum / currNum;
            }
            if (sign == '-') {
                currNum *= -1;
            }
            if (ind < n)
                sign = s.charAt(ind);
            st.push(currNum);
            i = ind + 1;
        }

        int ans=0;

        while(!st.isEmpty()){
            ans+=st.pop();
        }

        return ans;
    }
}
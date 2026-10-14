class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length();
        if (n <= 1) return s;

        StringBuilder combined = new StringBuilder();
        combined.append(s).append('#').append(new StringBuilder(s).reverse());

        int m = combined.length();
        int[] lps = new int[m];

        for (int i = 1, len = 0; i < m; ) {
            if (combined.charAt(i) == combined.charAt(len)) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int longestPrefix = lps[m - 1];

        StringBuilder result = new StringBuilder();
        result.append(new StringBuilder(s.substring(longestPrefix)).reverse());
        result.append(s);

        return result.toString();
    }
}
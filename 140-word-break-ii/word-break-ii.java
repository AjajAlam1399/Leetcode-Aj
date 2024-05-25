class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        int n = wordDict.size();
        Map<String, Integer> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            map.put(wordDict.get(i), 1);
        }
        List<String> ans = new ArrayList<>();

        fun(0, s, "", map, ans);
        return ans;
    }

    void fun(int ind, String s, String subans, Map<String, Integer> map, List<String> ans) {

        if (ind == s.length()) {
            String currans = subans.substring(0, subans.length()-1);
            ans.add(currans);
            return;
        }

        for (int i = ind; i < s.length(); i++) {
            String str = s.substring(ind, i + 1);
            if (map.containsKey(str)) {
                fun(i + 1, s, subans + str + " ", map,ans);
            }
        }
    }

}
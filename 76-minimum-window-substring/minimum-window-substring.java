class Solution {
    public String minWindow(String s, String t) {
        int n1 = s.length();
        int n2 = t.length();

        int i = -1, j = -1;
        int st = -1, en = -1;
        int ansLen = Integer.MAX_VALUE;
        int len = 0;

        HashMap<Character, Integer> map1 = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();

        for (int ind = 0; ind < n2; ind++) {
            map2.compute(t.charAt(ind), (id, val) -> {
                if (val == null)
                    val = 0;
                return val+1;
            });
        }

        while (true) {

            boolean f1 = false;
            boolean f2 = false;

            while (i < n1 - 1) {
                f1 = true;
                i++;
                map1.compute(s.charAt(i), (id, val) -> {
                    if (val == null)
                        val = 0;
                    return val+1;
                });
                if (map2.containsKey(s.charAt(i)) && map1.get(s.charAt(i)) <= map2.get(s.charAt(i))) {
                    len++;
                }
                if (len == n2) {
                    // System.out.println("first-" + i + "," + len);
                    break;
                }
            }

            while (j < i) {
                f2 = true;
                if (len == n2) {
                    // System.out.println("Second" + i + "," + j);
                    int currLen = i - j;
                    if (currLen <= ansLen) {
                        ansLen = currLen;
                        st = j + 1;
                        en = i;
                    }
                }
                j++;
                char ch = s.charAt(j);
                int charcnt;
                if (map1.get(ch) == 1) {
                    map1.remove(ch);
                    charcnt = 0;
                } else {
                    charcnt = map1.compute(ch, (id, val) -> {
                        return val-1;
                    });
                }
                // System.out.println(charcnt + "," + map2.get(ch));

                if (map2.containsKey(ch) && charcnt < map2.get(ch)) {
                    len--;
                }
                if (len < n2)
                    break;
            }

            if (!f1 && !f2)
                break;
        }
        if (ansLen == Integer.MAX_VALUE)
            return "";
        // System.out.println(ansLen);
        return s.substring(st, en + 1);

    }
}
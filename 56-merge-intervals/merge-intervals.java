class Solution {
    public int[][] merge(int[][] intervals) {

        Arrays.sort(intervals, (a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        list.add(new ArrayList<>());
        list.get(0).add(intervals[0][0]);
        list.get(0).add(intervals[0][1]);

        for (int i = 1; i < intervals.length; i++) {
            if (list.get(list.size() - 1).get(1) >= intervals[i][0]) {
                list.get(list.size() - 1).set(1, Math.max(list.get(list.size() - 1).get(1), intervals[i][1]));
            } else {
                list.add(new ArrayList<>());
                list.get(list.size() - 1).add(intervals[i][0]);
                list.get(list.size() - 1).add(intervals[i][1]);
            }
        }

        int[][] ans = new int[list.size()][2];

        for (int i = 0; i < list.size(); i++) {
            ans[i][0] = list.get(i).get(0);
            ans[i][1] = list.get(i).get(1);
        }

        return ans;

    }
}
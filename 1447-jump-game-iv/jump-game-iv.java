class Solution {
    class Pair {
        public int node;
        public int level;

        public Pair(int node, int level) {
            this.node = node;
            this.level = level;
        }
    };

    public int minJumps(int[] nums) {
        int n = nums.length;
        boolean visted[] = new boolean[n];
        Arrays.fill(visted, false);
        Map<Integer, ArrayList<Integer>> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            map.computeIfAbsent(nums[i], (key) -> new ArrayList<>()).add(i);
        }
        Set<Integer>valueVisted = new HashSet<>();

        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(0, 0));

        visted[0] = true;

        while (!q.isEmpty()) {
            Pair p = q.poll();
            int node = p.node;
            int level = p.level;
            if (node == n - 1)
                return level;

            if (node - 1 >= 0 && !visted[node - 1]) {
                q.offer(new Pair(node - 1, level + 1));
                visted[node - 1] = true;
            }

            if (node + 1 < n && !visted[node + 1]) {
                q.offer(new Pair(node + 1, level + 1));
                visted[node + 1] = true;
            }
            if (map.containsKey(nums[node]) && !valueVisted.contains(nums[node]) ) {
                valueVisted.add(nums[node]);
                for (int ind : map.get(nums[node])) {
                    if (!visted[ind]) {
                        q.offer(new Pair(ind, level + 1));
                        visted[ind] = true;
                    }
                }
            }

        }
        return -1;
    }
}
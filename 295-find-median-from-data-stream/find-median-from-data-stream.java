class MedianFinder {
    private static int id = 0;

    private class Pair {

        public int val;
        public int id;

        public Pair(int val) {
            this.val = val;
            this.id = MedianFinder.id;
            MedianFinder.id++;
        }
    };

    private TreeSet<Pair> lower;
    private TreeSet<Pair> upper;

    public MedianFinder() {
        lower = new TreeSet<>((a, b) -> {
            if(Integer.compare(a.val,b.val)==0) return Integer.compare(a.id, b.id);
            return Integer.compare(a.val, b.val);
        });
        upper = new TreeSet<>((a, b) -> {
            if(Integer.compare(a.val,b.val)==0) return Integer.compare(a.id, b.id);
            return Integer.compare(a.val, b.val);
        });
    }

    public void addNum(int num) {
        if (lower.size() == 0 || lower.last().val >= num) {
            lower.add(new Pair(num));
        } else {
            upper.add(new Pair(num));
        }
        rebalance();
    }

    public double findMedian() {

        if (upper.size() == lower.size()) {
            return ((double) lower.last().val + (double) upper.first().val) / 2.0;
        }
        if (upper.size() > lower.size()) {
            return (double) upper.first().val;
        }
        return lower.last().val;

    }

    private void rebalance() {
        int size1 = lower.size();
        int size2 = upper.size();

        if (Math.abs(size1 - size2) > 1) {
            if (size1 > size2) {
                Pair p = lower.pollLast();
                upper.add(p);
            } else {
                Pair p = upper.pollFirst();
                lower.add(p);
            }
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
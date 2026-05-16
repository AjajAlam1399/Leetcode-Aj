class LFUCache {

    private class Node {
        public int key;
        public int value;
        public int currFreq;
        public Node next;
        public Node prev;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.currFreq = 1;
            this.next = null;
            this.prev = null;
        }
    };

    private class ListNode {
        public Node Head;
        public Node Tail;
        public int size;

        public ListNode() {
            this.Head = new Node(-1, -1);
            this.Tail = new Node(-1, -1);
            this.Head.next = this.Tail;
            this.Tail.prev = this.Head;
            this.size = 0;
        }

        public void insertAtHead(Node node) {
            Node currHeadNext = Head.next;
            Head.next = node;
            node.prev = Head;
            node.next = currHeadNext;
            currHeadNext.prev = node;
            this.size++;
        }

        public void deleteNode(Node node) {
            Node currNodeNext = node.next;
            Node currNodePrev = node.prev;
            currNodeNext.prev = currNodePrev;
            currNodePrev.next = currNodeNext;
            this.size--;
        }

        public Node evictNode() {
            Node node = Tail.prev;
            deleteNode(node);
            return node;
        }

    };

    private HashMap<Integer, Node> keyMap;
    private HashMap<Integer, ListNode> freqMap;
    private int minFreq;
    private int capacity;
    private int size;

    public LFUCache(int capacity) {
        keyMap = new HashMap<>();
        freqMap = new HashMap<>();
        this.minFreq = 1;
        this.capacity = capacity;
        this.size = 0;
    }

    public int get(int key) {
        if (!keyMap.containsKey(key)) {
            return -1;
        }
        Node node = keyMap.get(key);
        updateFrequency(node);

        return node.value;
    }

    public void put(int key, int value) {
        if (keyMap.containsKey(key)) {
            Node node = keyMap.get(key);
            node.value = value;
            updateFrequency(node);
        } else {
            if (Integer.compare(this.size, this.capacity) == 0) {
                ListNode ln = freqMap.get(minFreq);
                Node evictedNode = ln.evictNode();
                keyMap.remove(evictedNode.key);
                if (ln.size == 0) {
                    freqMap.remove(minFreq);
                }
                this.size--;
            }
            this.minFreq = 1;
            Node node = new Node(key, value);
            freqMap.putIfAbsent(minFreq, new ListNode());
            freqMap.get(minFreq).insertAtHead(node);
            keyMap.put(key, node);
            this.size++;
        }
    }

    private void updateFrequency(Node node) {
        int nodeFreq = node.currFreq;
        ListNode ln = freqMap.get(nodeFreq);
        ln.deleteNode(node);
        if (ln.size == 0) {
            freqMap.remove(nodeFreq);
            if (Integer.compare(this.minFreq, nodeFreq) == 0) {
                this.minFreq++;
            }
        }
        node.currFreq++;
        freqMap.putIfAbsent(node.currFreq, new ListNode());
        freqMap.get(node.currFreq).insertAtHead(node);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
class LRUCache {

    private class Node {
        public int val;
        public int key;
        Node prev;
        Node next;

        public Node(int key, int val) {
            this.val = val;
            this.key = key;
            prev = null;
            next = null;
        }

        public int getKey() {
            return key;
        }
        public void setValue(int val){
            this.val = val;
        }
    }

    Map<Integer, Node> map;
    Node Head;
    Node Tail;
    int capacity;

    public LRUCache(int capacity) {
        map = new HashMap<>();
        this.capacity = capacity;
        Head = new Node(-1, -1);
        Tail = new Node(-1, -1);
        Head.next = Tail;
        Tail.prev = Head;
    }

    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1;
        }
        Node node = map.get(key);
        deleteNode(node);
        insertAtHead(node);
        return node.val;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.setValue(value);
            deleteNode(node);
            insertAtHead(node);
        } else {
            Node node;
            if (map.size() == capacity) {
                node = Tail.prev;
                deleteNode(node);
                map.remove(node.getKey());
            }
            node = new Node(key, value);
            insertAtHead(node);
            map.put(key, node);
        }
    }

    private void insertAtHead(Node node) {
        Node currHeadNext = Head.next;
        Head.next = node;
        node.prev = Head;
        node.next = currHeadNext;
        currHeadNext.prev = node;
    }

    private void deleteNode(Node node) {
        Node nodeNext = node.next;
        Node nodePrev = node.prev;

        nodePrev.next = nodeNext;
        nodeNext.prev = nodePrev;
    }

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
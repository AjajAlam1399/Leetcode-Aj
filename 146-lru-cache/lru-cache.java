class LRUCache {

    class Node {
        public int key;
        public int value;
        public Node next;
        public Node prev;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.next = null;
            this.prev = null;
        }
    }

    Node head;
    Node tail;
    int capacity;
    Map<Integer, Node> map = new HashMap<>();

    public LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head.next = tail;
        tail.prev = head;

        this.capacity = capacity;
    }

    private void insertAtHead(Node node){
        Node headNext=head.next;
        head.next=node;
        node.next=headNext;
        node.prev=head;
        headNext.prev=node;
    }

    private Node evictTail() {
        Node evictNode = tail.prev;
        Node evictPrevNode = evictNode.prev;
        evictPrevNode.next = tail;
        tail.prev = evictPrevNode;

        return evictNode;
    }

    private void deleteNode(Node node) {
        Node prevNode = node.prev;
        Node nextNode = node.next;

        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }

    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1;
        }

        Node node = map.get(key);
        deleteNode(node);
        insertAtHead(node);
        return node.value;
    }

    public void put(int key, int value) {
        Node node;
        if (map.containsKey(key)) {
            node = map.get(key);
            node.value = value;
            deleteNode(node);
            insertAtHead(node);
        } else {
            if (map.size() == capacity) {
                node = evictTail();
                map.remove(node.key);
            }
            node = new Node(key, value);
            map.put(key, node);
            insertAtHead(node);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
class LRUCache {

    class Node {
        public int key;
        public int val;
        public Node prev;
        public Node next;

        public Node(int key , int val){
            this.key = key;
            this.val=val;
            this.prev = null;
            this.next = null;
        }
    }

    Node Head;
    Node Tail;
    Map<Integer, Node> map;
    int capacity;
    int size;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        Head = new Node(-1,-1);
        Tail = new Node(-1,-1);
        Head.next = Tail;
        Tail.prev = Head;
        map = new HashMap<>();
        this.size = 0;
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
            node.val = value;
            deleteNode(node);
            insertAtHead(node);
            return ;
        }
        if(this.size == this.capacity){
            Node node = Tail.prev;
            deleteNode(node);
            map.remove(node.key);
            this.size--;
        }
        Node node = new Node(key, value);
        map.put(key,node);
        insertAtHead(node);
        this.size++;
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
        Node nodeprev = node.prev;

        nodeNext.prev = nodeprev;
        nodeprev.next = nodeNext;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
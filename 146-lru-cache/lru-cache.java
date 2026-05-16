class LRUCache {

    private class Node {
        public int key;
        public int value;
        public Node prev;
        public Node next;

        public Node(int key ,int value){
            this.key = key;
            this.value = value;
            this.prev=null;
            this.next = null;
        }
    };

    private Node Head;
    private Node Tail;

    private Map<Integer,Node>map;
    private int size;
    private int capacity;

    public LRUCache(int capacity) {
        this.Head = new Node(-1,-1);
        this.Tail = new Node(-1,-1);
        this.Head.next = Tail;
        this.Tail.prev = Head;
        map = new HashMap<>();
        this.size =0;
        this.capacity = capacity;
    }

    private void insertAtHead(Node node){
        Node headNext = Head.next;
        headNext.prev=node;
        node.next=headNext;
        node.prev=Head;
        Head.next=node;
    }

    private void deleteNode(Node node){
        Node prevNode = node.prev;
        Node nextNode = node.next;
        prevNode.next=nextNode;
        nextNode.prev=prevNode;
    }
    
    public int get(int key) {
        if(!map.containsKey(key)){
            return -1;
        }
        Node node = map.get(key);
        deleteNode(node);
        insertAtHead(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)){
            Node node = map.get(key);
            node.value = value;
            deleteNode(node);
            insertAtHead(node);
        }
        else{
            if(Integer.compare(size,capacity)==0){
                Node deleteNode = Tail.prev;
                deleteNode(deleteNode);
                map.remove(deleteNode.key);
                this.size--;
            }
            Node node = new Node(key,value);
            insertAtHead(node);
            map.put(key,node);
            this.size++;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
import java.util.*;

class LFUCache {

    /* ---------------- NODE ---------------- */
    private class Node {
        int key;
        int val;
        int freq;
        Node prev, next;

        Node(int key, int val) {
            this.key = key;
            this.val = val;
            this.freq = 1;
        }
    }

    /* ---------------- DOUBLY LIST ---------------- */
    private class List {
        int size;
        Node head, tail;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head.next = tail;
            tail.prev = head;
            size = 0;
        }

        void insertAtHead(Node node) {
            Node next = head.next;

            head.next = node;
            node.prev = head;

            node.next = next;
            next.prev = node;

            size++;
        }

        void deleteNode(Node node) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
            size--;
        }

        Node removeLRU() {
            if (size == 0)
                return null;
            Node node = tail.prev;
            deleteNode(node);
            return node;
        }
    }

    /* ---------------- LFU STRUCTURE ---------------- */

    Map<Integer, Node> nodeMap; // key -> node
    Map<Integer, List> freqMap; // freq -> DLL

    int capacity;
    int minFreq;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        nodeMap = new HashMap<>();
        freqMap = new HashMap<>();
        minFreq = 0;
    }

    /* ---------------- GET ---------------- */

    public int get(int key) {
        Node node = nodeMap.get(key);
        if (node == null)
            return -1;

        updateFrequency(node);
        return node.val;
    }

    /* ---------------- PUT ---------------- */

    public void put(int key, int value) {

        if (capacity == 0)
            return;

        // key already exists
        if (nodeMap.containsKey(key)) {
            Node node = nodeMap.get(key);
            node.val = value;
            updateFrequency(node);
            return;
        }

        // eviction required
        if (nodeMap.size() == capacity) {
            List minList = freqMap.get(minFreq);
            Node lru = minList.removeLRU();
            nodeMap.remove(lru.key);

            if (minList.size == 0) {
                freqMap.remove(minFreq);
            }
        }

        // insert new node
        Node node = new Node(key, value);
        nodeMap.put(key, node);

        freqMap
                .computeIfAbsent(1, k -> new List())
                .insertAtHead(node);

        minFreq = 1;
    }

    /* ---------------- CORE LFU STEP ---------------- */

    private void updateFrequency(Node node) {

        int freq = node.freq;
        List oldList = freqMap.get(freq);

        oldList.deleteNode(node);

        if (oldList.size == 0) {
            freqMap.remove(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        node.freq++;

        freqMap
                .computeIfAbsent(node.freq, k -> new List())
                .insertAtHead(node);
    }
}

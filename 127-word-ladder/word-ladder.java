class Solution {
    private class Node {
        public String word;
        public int dist;

        public Node(String word, int dist) {
            this.word = word;
            this.dist = dist;
        }
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> seen = new HashSet<String>();
        Queue<Node> q = new LinkedList<>();
        Set<String> wList= new HashSet<String>();

        for(int i=0;i<wordList.size();i++){
            wList.add(wordList.get(i));
        }

        seen.add(beginWord);
        q.offer(new Node(beginWord, 1));

        while (!q.isEmpty()) {
            Node node = q.poll();
            String st = node.word;
            if (st.equals(endWord)) {
                return node.dist;
            }
            StringBuilder currStr = new StringBuilder(node.word);

            for (int ind = 0; ind < currStr.length(); ind++) {
                char currCh = currStr.charAt(ind);
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if(currCh!=ch){
                        StringBuilder tempStr = new StringBuilder(node.word);
                        tempStr.setCharAt(ind,ch);
                        if(!seen.contains(tempStr.toString()) && wList.contains(tempStr.toString())){
                            // System.out.println(tempStr);
                            q.offer(new Node(tempStr.toString(),node.dist+1));
                            seen.add(tempStr.toString());
                        }
                    }
                }
            }
        }

        return 0;
    }
}
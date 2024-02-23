
class Solution {
    class Pair<S,T>{
        private S first;
        private T second;
        Pair(S first,T second){
            this.first=first;
            this.second=second;
        }
        S getFirst(){
            return first;
        }
        T getSecond(){
            return second;
        }
    }
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        ArrayList<ArrayList<Pair<Integer,Integer>>>graph=new ArrayList<ArrayList<Pair<Integer,Integer>>>(n);
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<Pair<Integer,Integer>>());
        }
        for(int i=0;i<flights.length;i++){
            graph.get(flights[i][0]).add(new Pair(flights[i][1],flights[i][2]));
        }
        int dist[]=new int[n];
        Arrays.fill(dist,Integer.MAX_VALUE);
        Queue<Pair<Integer,Pair<Integer,Integer>>>q=new LinkedList<Pair<Integer,Pair<Integer,Integer>>>();
        q.offer(new Pair(0,new Pair(src,0)));
        dist[src]=0;
        while(!q.isEmpty()){
            Pair<Integer,Pair<Integer,Integer>>top=q.poll();
            int currFlight=top.getFirst();
            int currNode=top.getSecond().getFirst();
            int currdist=top.getSecond().getSecond();
            if(currFlight>k){
                continue;
            }
            for(Pair<Integer,Integer>pair:graph.get(currNode)){
                int adjNode=pair.getFirst();
                int wt=pair.getSecond();

                if(dist[adjNode]>currdist+wt){
                    dist[adjNode]=currdist+wt;
                    q.offer(new Pair(currFlight+1,new Pair(adjNode,dist[adjNode])));
                }
            }
        }
        return dist[dst]==Integer.MAX_VALUE?-1:dist[dst];
    }
}
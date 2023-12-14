class Pair<M,N>{
   private M first;
   private N second;
    Pair(M first,N second){
        this.first=first;
        this.second=second;
    }
    public M getFirst(){
        return this.first;
    }
    public N getSecond(){
        return this.second;
    }
}
class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
         
        int n=grid.length;
        int m=grid[0].length;
        List<Pair<Integer,Integer>>rowm=new ArrayList<>();
         List<Pair<Integer,Integer>>colm=new ArrayList<>();

        for(int i=0;i<n;i++){
            int zero=0,one=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    zero++;
                }
                else{
                    one++;
                }
            }
            rowm.add(new Pair(one,zero));
        }

        for(int i=0;i<m;i++){
            int zero=0,one=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==0){
                    zero++;
                }
                else{
                    one++;
                }
            }
            colm.add(new Pair(one,zero));
        }
        for(int i=0;i<n;i++){
                Pair<Integer,Integer> it1=rowm.get(i);
            for(int j=0;j<m;j++){
                Pair<Integer,Integer> it2=colm.get(j);
                grid[i][j]=it1.getFirst()+it2.getFirst()-it1.getSecond()-it2.getSecond();
            }
        }
        return grid;
    }
}
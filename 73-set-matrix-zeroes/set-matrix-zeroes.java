class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> rowSet = new HashSet<>();
        Set<Integer> colSet = new HashSet<>();

        int n = matrix.length;
        int m = matrix[0].length;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(!rowSet.contains(i)){
                        rowSet.add(i);
                    }

                    if(!colSet.contains(j)){
                        colSet.add(j);
                    }
                }
            }
        }

        for(int ele : rowSet){
            // System.out.println("rowSet-"+ele);
            for(int j=0;j<m;j++){
                matrix[ele][j]=0;
            }
        }

        for(int ele : colSet){
            // System.out.println("colSet-"+ele);
            for(int j=0;j<n;j++){
                matrix[j][ele] = 0;
            }
        }
    }
}
class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int [] leftArr = new int[n];
        leftArr[0]=1;

        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                leftArr[i]=leftArr[i-1]+1;
            }
            else{
                leftArr[i]=1;
            }
            // System.out.println(leftArr[i]);
        }

        int ans=leftArr[n-1];

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                leftArr[i]=Math.max(leftArr[i],leftArr[i+1]+1);
            }
            ans+=leftArr[i];
            // System.out.println(leftArr[i]);
        }

        return ans;
    }
}
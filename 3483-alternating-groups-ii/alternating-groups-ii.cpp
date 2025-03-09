class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int cnt=0;
        int i=1,j=0;

        while(i<2*n){
            if(j>=n){
                break;
            }
            if(colors[(i-1)%n]==colors[i%n]){
                j=i;
            }
            if((i-j+1)==k){
                cnt++;
                j++;
            }
            i++;
        }
        return cnt;
    }
};
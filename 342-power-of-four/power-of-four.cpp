class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0){
            int x=log2(n)/log2(4);
            return log2(n)==x*log2(4);
        }
        return false;
    }
};
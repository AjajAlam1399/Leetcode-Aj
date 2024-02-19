class Solution {
public:
    bool isPowerOfTwo(long long n) {
        if(n==0){
            return false;
        }
        long long x=n;
        return (x&(x-1))==0;
    }
};
class Solution {
public:
    int kthGrammar(int n, int k) {
        
        n=1<<(n-1);
        bool zero=true;
        while(n!=1){
            n/=2;
            if(k>n){
                k-=n;
                zero=!zero;
            }
        }
        return zero?0:1;
    }
};
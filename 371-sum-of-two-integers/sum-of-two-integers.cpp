class Solution {
public:
    int getSum(int a, int b) {
        
        int carry=b;
        int sum=a;
        while(carry){
            sum=a^b;
            carry=(a&b)<<1;
            a=sum;
            b=carry;
        }
        return sum;
    }
};
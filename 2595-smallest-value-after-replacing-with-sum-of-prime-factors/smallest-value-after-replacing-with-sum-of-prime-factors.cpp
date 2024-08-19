class Solution {
public:
    int smallestValue(int n) {
        int ans = 0;
        int prev=n;
        while (true) {
            int sum = 0;
            bool flag = false;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    flag=true;
                    while (n % i == 0) {
                        sum += i;
                        n /= i;
                    }
                }
            }
            int curr=0;
            if(n && n!=1){
                curr=n+sum;
            }
            else{
                curr=sum;
            }
            if(prev==curr)return curr;
            prev=curr;
            n=curr;
        }
        return ans;
    }
};
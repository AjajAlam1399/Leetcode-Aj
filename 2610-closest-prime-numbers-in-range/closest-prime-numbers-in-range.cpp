class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int num1=-1,num2=-1,num3=-1;

        for(int i=left;i<=right;i++){
            bool flag=isPrime(i);

            if(flag){
                if(num1==-1){
                    num1=i;
                }
                else if(num2==-1){
                    num2=i;
                }
                else{
                    if(num3==-1){
                        num3=i;
                        if(i-num2<num2-num1){
                            num1=num2;
                            num2=i;
                        }
                    }
                    else if(i-num3<num2-num1){
                        num1=num3;
                        num2=i;
                        num3=i;
                    }
                    else{
                        num3=i;
                    }
                }
            }
        }
        if(num1==-1 || num2==-1)return {-1,-1};
        return {num1,num2};
    }

    bool isPrime(int num){
        if(num==1)return false;
        if(num==2)return true;

        for(int i=2;i*i<=num;i++){
            if(num%i==0)return false;
        }
        return true;
    }
};
class Solution {
public:
    int findComplement(int num) {
        
     int  ans=0;
     int ind=0;
       while(num){
        int bit=((num)&(1<<0));
        if(!bit){
            ans|=(1<<ind);
        }
        ind++;
        num=num>>1;
       }

       return ans;
    }
};
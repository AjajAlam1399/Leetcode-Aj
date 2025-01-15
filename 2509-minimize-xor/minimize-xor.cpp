class Solution {
public:
    int minimizeXor(int a, int b) {
        int temp=b;
        
        int setB=0;
        
        int setA=0;
        
        for(int i=31;i>=0;i--){
            int bitb=(b>>i)&1;
            int bita=(a>>i)&1;
            if(bitb){
                setB++;
            }
            if(bita){
                setA++;
            }
        }
        
        if(setA==setB){
            return a;
        }
        else if(setA>setB){
            int ans=0;
        
            for(int i=31;i>=0;i--){
                int bit=(a>>i)&1;
                if(setB){
                    if(bit){
                        ans=ans|1<<i;
                        setB--;
                    }
                }
                else{
                    break;
                }
            }
            
            return ans;
        }
        
            int rem=setB-setA;
            int ans=a;
            for(int i=0;i<=31;i++){
                int bit=(a>>i)&1;
                if(!bit){
                    ans=ans|1<<i;
                    rem--;
                }
                
                if(rem==0){
                    break;
                }
            }
            
            return ans;
    }
};
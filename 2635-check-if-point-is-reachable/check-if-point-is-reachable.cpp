class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        return fun(targetX,targetY);
    }

    bool fun(int x,int y){

        if(x==1 || y==1)return true;

        if(x==0 || y==0)return false;

        if(x>y){
            if(x%2==0){
                if(fun(x/2,y))return true;
                if(fun(x%y,y))return true;
            }
            else{
               if(fun(x%y,y))return true; 
            }
        }if(x<y){
            if(y%2==0){
                if(fun(x,y/2))return true;
                if(fun(x,y%x))return true;
            }
            else{
                if(fun(x,y%x))return true;
            }
        }
        else{
            if((x&(x-1))){
                return false;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
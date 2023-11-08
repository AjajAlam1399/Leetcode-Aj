class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int xdis=abs(sx-fx);
        int ydis=abs(sy-fy);

        int minstep=min(xdis,ydis)+abs(xdis-ydis);
        if(minstep==0 ){
            return t==1?false:true;
        }
        return t>=minstep?true:false;
    }
};
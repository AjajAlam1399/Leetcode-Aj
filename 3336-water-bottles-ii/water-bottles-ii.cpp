class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int ans=numBottles;
        int e=numBottles;
        int ex=numExchange;

        while(e>=ex && e!=0){
            ans++;
            e=(e-ex+1);
            ex++;
        }
        return ans;
    }
};
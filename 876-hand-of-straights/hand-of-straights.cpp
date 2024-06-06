class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;

        sort(hand.begin(),hand.end());

        vector<bool>visted(n,false);

        for(int i=0;i<n;i++){
            bool flag=false;
            int cnt=1;
            int prev=hand[i];
            if(!visted[i]){
                visted[i]=true;
                for(int j=0;j<n;j++){
                    if(cnt==groupSize){
                        flag=true;
                        break;
                    }
                    if(hand[j]==prev+1 && !visted[j]){
                        cnt++;
                        prev=prev+1;
                        visted[j]=true;
                    }
                    if(cnt==groupSize){
                        flag=true;
                        break;
                    }
                }
                if(!flag)return false;
            }
            
        }

        return true;
    }
};
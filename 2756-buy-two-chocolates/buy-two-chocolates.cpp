class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        priority_queue<int>pq;

        for(int i=0;i<prices.size();i++){
            if(pq.size()<2){
                pq.push(prices[i]);
            }
            else{
                if(pq.top()>prices[i]){
                    pq.pop();
                    pq.push(prices[i]);
                }
            }
        }
        int sum=0;
        sum+=pq.top();
        pq.pop();
       sum+= pq.top();
        return sum<=money?money-sum:money;
    }
};
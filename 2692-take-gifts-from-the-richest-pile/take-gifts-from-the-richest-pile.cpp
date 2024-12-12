class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
       priority_queue<int>pq;

       for(int i=0;i<gifts.size();i++){
        pq.push({gifts[i]});
       } 
       while(!pq.empty() && k){
        auto it =pq.top();
        pq.pop();
        int num=sqrt(it);
        
        if(num>0){
            pq.push(num);
        }

        k--;
       }
       long long ans=0;

       while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
       }

       return ans;
    }
};
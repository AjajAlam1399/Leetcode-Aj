class Solution {
public:
    int nthUglyNumber(int nth) {
        
        unordered_set<long long>visted;
        long long arr[]={2,3,5};
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        pq.push(1);
        visted.insert(1);
        long long curr=1;
        for(int i=0;i<nth;i++){
            curr=pq.top();
            pq.pop();
            for(int j=0;j<3;j++){
                long long newn=curr*arr[j];
                if(visted.find(newn)==visted.end()){
                    visted.insert(newn);
                    pq.push(newn);
                }
            }
        }
        return curr;
    }

};
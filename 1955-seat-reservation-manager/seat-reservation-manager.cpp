class SeatManager {
    priority_queue<int,vector<int>,greater<int>>pq;
    int last;
public:
    SeatManager(int n) {
        last=0;
    }
    
    int reserve() {
        int ans;
        if(pq.empty()){
            last++;
            ans=last;
        }
        else{
             ans=pq.top();
            pq.pop();
        }
        return ans;
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber==last){
            last--;
        }
        else{
            pq.push(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
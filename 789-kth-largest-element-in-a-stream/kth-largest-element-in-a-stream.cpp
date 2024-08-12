class KthLargest {
    priority_queue<int,vector<int>,greater<int>>heap;
    int kth;

public:
    KthLargest(int k, vector<int>& nums) {
        this->kth = k;
        for (int i = 0; i < nums.size(); i++) {
            if(heap.size()<kth){
                heap.push(nums[i]);
            }
            else{
                if(heap.top()<nums[i]){
                    heap.pop();
                    heap.push(nums[i]);
                }
            }
        }
    }

    int add(int val) {
        if(heap.size()<kth){
                heap.push(val);
            }
            else{
                if(heap.top()<val){
                    heap.pop();
                    heap.push(val);
                }
            }

        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class KthLargest {
    multiset<int>heap;
    int kth;

public:
    KthLargest(int k, vector<int>& nums) {
        this->kth = k;
        for (int i = 0; i < nums.size(); i++) {
            heap.insert(nums[i]);
        }
    }

    int add(int val) {
        heap.insert(val);
        int k=0;
        int ans=0;
        for(auto it=heap.rbegin();it!=heap.rend();++it){
            k++;
            if(k==kth){
                ans=*it;
                break;
            }
        }

        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
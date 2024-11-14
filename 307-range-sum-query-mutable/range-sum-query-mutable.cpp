class NumArray {
    vector<int>blockArr;
    vector<int>arr;
    int block_size;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        block_size=ceil(sqrt(n));
        blockArr.resize(block_size);
        arr.resize(n);
        int block_indx=-1;
        for(int i=0;i<n;i++){
            arr[i]=nums[i];
            if(i%block_size==0){
                block_indx++;
            }
            blockArr[block_indx]+=arr[i];

        }
    }
    
    void update(int index, int val) {
        int ind=index/block_size;
        blockArr[ind]+=val-arr[index];
        arr[index]=val;
    }
    
    int sumRange(int left, int right) {
        int sum=0;

        while(left<right && left%block_size!=0 && left!=0){
            sum+=arr[left];
            left++;
        }
        while(left+block_size-1<=right){
            sum+=blockArr[left/block_size];
            left+=block_size;
        }
        while(left<=right){
            sum+=arr[left];
            left++;
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
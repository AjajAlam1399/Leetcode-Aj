class NumArray {
    vector<int>segTree;
    int high;    
    private: 
    void build (int l,int r,int ind,vector<int>&nums){
        if(l==r){
            segTree[ind]=nums[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,2*ind+1,nums);
        build(mid+1,r,2*ind+2,nums);
        segTree[ind]=segTree[2*ind+1]+segTree[2*ind+2];
    }

    int query(int l,int r,int ind,int lind,int rind){
        if(l>=lind && r<=rind)return segTree[ind];
        if(l>rind || r<lind)return 0;
        int mid=(l+r)>>1;
        int left=query(l,mid,2*ind+1,lind,rind);
        int right=query(mid+1,r,2*ind+2,lind,rind);
        return left+right;
    }

    void pointUpdate(int l,int r,int ind,int node,int val){
        if(l==r){
            segTree[ind]=val;
            return ;
        }
        int mid=(l+r)>>1;
        if(node>=l && node<=mid){
            pointUpdate(l,mid,2*ind+1,node,val);
        }
        else{
            pointUpdate(mid+1,r,2*ind+2,node,val);
        }
        segTree[ind]=segTree[2*ind+1]+segTree[2*ind+2];
    }
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        this->high=n;
        segTree.resize(4*n+1);
        build(0,n-1,0,nums);
    }
    
    void update(int index, int val) {
        int r=high;
        pointUpdate(0,r-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
         int r=high;
        return query(0,r-1,0,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
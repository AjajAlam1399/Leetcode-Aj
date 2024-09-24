class Node{
    public:
    unordered_map<int,int>map;
};

class RangeFreqQuery {
    vector<Node>seg;
    int n;
    void build(int left,int right,int ind,vector<int>&arr){
        if(left==right){
            seg[ind].map[arr[left]]++;
            return;
        }
        int mid=(left+right)>>1;
        build(left,mid,2*ind+1,arr);
        build(mid+1,right,2*ind+2,arr);
        for(auto it : seg[2*ind+1].map){
            seg[ind].map[it.first]+=it.second;
        }
        for(auto it : seg[2*ind+2].map){
            seg[ind].map[it.first]+=it.second;
        }
        return ;
    }
    int segQuery(int l,int r,int ind,int low,int heigh,int val){
        if(low>r || heigh<l){
            return 0;
        }
        if(l>=low && r<=heigh){
            return seg[ind].map[val];
        }
        int mid=(l+r)>>1;
        return segQuery(l,mid,2*ind+1,low,heigh,val)+segQuery(mid+1,r,2*ind+2,low,heigh,val);
    }
public:
    RangeFreqQuery(vector<int>& arr) {
        this->n=arr.size();
        seg=vector<Node>(4*n+1);
        build(0,n-1,0,arr);
    }
    
    int query(int left, int right, int value) {
        return segQuery(0,n-1,0,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
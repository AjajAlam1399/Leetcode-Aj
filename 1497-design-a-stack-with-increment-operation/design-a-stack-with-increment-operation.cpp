class CustomStack {
    vector<pair<int,int>>vec;
    int n;
    int i;
public:
    CustomStack(int maxSize) {
        this->n=maxSize;
        this->i=0;
        vec=vector<pair<int,int>>(maxSize+1);
    }
    
    void push(int x) {
        if(i+1<=n){
            i++;
            vec[i]={x,0};
        }
    }
    
    int pop() {
        if(i==0)return -1;
        else if(i==1){
            int ans=vec[i].first+vec[i].second;
            vec[i]={0,0};
            i--;
            return ans;
        }
        int ans=vec[i].first+vec[i].second;
            vec[i-1].second+=vec[i].second;
             vec[i]={0,0};
            i--;
            return ans;
    }
    
    void increment(int k, int val) {
        if(k>i){
            vec[i].second+=val;
        }
        else{
            vec[k].second+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
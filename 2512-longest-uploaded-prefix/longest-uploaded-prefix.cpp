class BIT{
    vector<int>bit;
    int n;
    public:
    BIT(int n){
        this->n=n;
        bit=vector<int>(n+1,0);
    }
    void update(int idx){
        while(idx<=n){
            bit[idx]+=1;
            idx+=(idx&-idx);
        }
    }
    int query(int idx){
        int sum=0;
        while(idx>0){
            sum+=bit[idx];
            idx-=(idx&-idx);
        }
        return sum;
    }
};
class LUPrefix {
    vector<int>bit;
    int n;
    void update(int idx){
        while(idx<=n){
            bit[idx]+=1;
            idx+=(idx&-idx);
        }
    }
    int query(int idx){
        int sum=0;
        while(idx>0){
            sum+=bit[idx];
            idx-=(idx&-idx);
        }
        return sum;
    }
public:
    LUPrefix(int n) {
    this->n=n;
    bit=vector<int>(n+1,0); 
    }
    
    void upload(int video) {
        update(video);
    }
    
    int longest() {
        int l=0 , r=n;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int count=query(mid);
            if(count==mid){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
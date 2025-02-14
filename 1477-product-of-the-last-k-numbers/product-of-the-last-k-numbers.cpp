class ProductOfNumbers {
    using ll=long long ;
    unordered_map<int,ll>map;
    ll product;
    ll cnt;
    int lastZero;
public:
    ProductOfNumbers() {
        this->product=1;
        this->cnt=0;
        this->lastZero=-1;
    }
    
    void add(int num) {
        cnt++;
        if(num>0){
            product*=(ll)num;
        }
        else{
            lastZero=cnt;
            product=1;
        }
        map[cnt]=product;
    }
    
    int getProduct(int k) {
        int ind=cnt-k;
        if(lastZero>ind)return 0;
        if(ind==0){
            return product;
        }
        return product/map[ind];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
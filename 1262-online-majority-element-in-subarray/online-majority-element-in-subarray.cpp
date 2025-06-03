class MajorityChecker {
    unordered_map<int,vector<int>>map;
    vector<int>arr;
    int n;
public:
    MajorityChecker(vector<int>& arr) {
        this->n=arr.size();
        this->arr=arr;
        for(int i=0;i<arr.size();i++){
            map[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for(int i=0;i<20;i++){
            int num=arr[randInd(left,right)];
            if(check(num,left,right)>=threshold){
                return num;
            }
        }

        return -1;
    }

    int check(int num,int l,int r){
        auto &vec=map[num];
        int lb=lower_bound(vec.begin(),vec.end(),l)-vec.begin();
        if(lb==n)return 0;
        int up=upper_bound(vec.begin(),vec.end(),r)-vec.begin();
        
        return up-lb;
    }

    int randInd(int l,int r){
        return l+rand()%(r-l+1);
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
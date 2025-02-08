class NumberContainers {
    unordered_map<int,set<int>>num;
    unordered_map<int,int>ind;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(ind.find(index)==ind.end()){
            ind[index]=number;
            num[number].insert(index);
        }
        else{
            num[ind[index]].erase(index);
            if(num[ind[index]].size()==0){
                num.erase(ind[index]);
            }
            ind[index]=number;
            num[number].insert(index);
        }
    }
    
    int find(int number) {
        if(num.find(number)==num.end())return -1;
        return *(num[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
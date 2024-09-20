class MyCalendar {
    vector<pair<int,int>>vec;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool ans=true;
        for(int i=0;i<vec.size();i++){
            if(end<=vec[i].first || start>=vec[i].second){
                continue;
            }
            else{
                ans=false;
                break;
            }
        }
        if(ans){
            vec.push_back({start,end});
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
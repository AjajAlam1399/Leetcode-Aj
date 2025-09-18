class cmp{
    public:
    bool operator()(const vector<int>&vec1,
    const vector<int>&vec2) const{
        if(vec1[0]==vec2[0]){
            return vec1[1]>vec2[1];
        }
        return vec1[0]>vec2[0];
    }
};
class TaskManager {
    unordered_map<int,pair<int,int>>task;
    set<vector<int>,cmp>set;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks){
            int userId=it[0];
            int taskId=it[1];
            int prior=it[2];
            set.insert({prior,taskId,userId});
            task[taskId]={userId,prior};
        }
    }
    
    void add(int userId, int taskId, int prior) {
        set.insert({prior,taskId,userId});
        task[taskId]={userId,prior};
    }
    
    void edit(int taskId, int newPrio) {
        auto it = task[taskId];
        int userId=it.first;
        int prevP=it.second;

        set.erase(set.find({prevP,taskId,userId}));
        task.erase(taskId);

        task[taskId]={userId,newPrio};
        set.insert({newPrio,taskId,userId});
    }
    
    void rmv(int taskId) {
        auto it = task[taskId];
        int userId=it.first;
        int prevP=it.second;

        set.erase(set.find({prevP,taskId,userId}));
        task.erase(taskId);
    }
    
    int execTop() {
        if(set.begin()==set.end())return -1;
        vector<int> it =*set.begin();
        int ans=it[2];
        set.erase(set.begin());
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
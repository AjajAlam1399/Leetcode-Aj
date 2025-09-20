class Router {
    queue<vector<int>> q;
    unordered_set<string>dup;
    unordered_map<int, vector<int>> destMap;
    int maxSize;

public:
    Router(int memoryLimit) { this->maxSize = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source)+"#"+to_string(destination)+"#"+to_string(timestamp);

        if(dup.find(key)!=dup.end())return false;

        if (q.size() == maxSize) {
            forwardPacket();
        }
        q.push({source, destination, timestamp});
        destMap[destination].push_back(timestamp);
        dup.insert(key);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.size() == 0) {
            return {};
        }
        vector<int> ans = q.front();
        string key = to_string(ans[0])+"#"+to_string(ans[1])+"#"+to_string(ans[2]);
        dup.erase(key);
        q.pop();
        destMap[ans[1]].erase(destMap[ans[1]].begin());
        return ans;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto ed=upper_bound(destMap[destination].begin(),destMap[destination].end(),endTime);
        auto st=lower_bound(destMap[destination].begin(),destMap[destination].end(),startTime);
        return ed-st;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
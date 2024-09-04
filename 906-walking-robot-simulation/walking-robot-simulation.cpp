class Solution {
    using ll = long long;

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        string dir = "N";
        ll i = 0, j = 0;
        int n = obstacles.size();
        unordered_set<string> set;

        for (int i = 0; i < n; i++) {
            string str =
                to_string(obstacles[i][0]) + "#" + to_string(obstacles[i][1]);
            set.insert(str);
        }

        ll ans = 0;
        n = commands.size();
        string str;
        for (int k = 0; k < n; k++) {
            int val = commands[k];
            if (val == -1) {
                if (dir == "N")
                    dir = "E";
                else if (dir == "E")
                    dir = "S";
                else if (dir == "S")
                    dir = "W";
                else if (dir == "W")
                    dir = "N";
            } else if (val == -2) {
                if (dir == "N")
                    dir = "W";
                else if (dir == "E")
                    dir = "N";
                else if (dir == "S")
                    dir = "E";
                else if (dir == "W")
                    dir = "S";
            } else {
                int cnt=1;
                if (dir == "N") {
                    for (int m = 1; m <= val; m++) {
                        j +=cnt;
                        str = to_string(i) + "#" +to_string(j);
                         if (set.find(str) != set.end()) {
                            j--;
                            break;
                        }
                    }
                } else if (dir == "S") {
                    for(int m=1;m<=val;m++){
                        j-=cnt;
                        str=to_string(i)+"#"+to_string(j);
                        if(set.find(str)!=set.end()){
                            j++;
                            break;
                        }
                    }
                } else if (dir == "E") {
                    for(int m=1;m<=val;m++){
                        i+=cnt;
                        str=to_string(i)+"#"+to_string(j);
                        if(set.find(str)!=set.end()){
                            i--;
                            break;
                        }
                    }
                } else if (dir == "W") {
                    for(int m=1;m<=val;m++){
                        i-=cnt;
                        str=to_string(i)+"#"+to_string(j);
                        if(set.find(str)!=set.end()){
                            i++;
                            break;
                        }
                    }
                }
                ans = max(ans, i * i + j * j);
            }
        }
        return ans;
    }
};
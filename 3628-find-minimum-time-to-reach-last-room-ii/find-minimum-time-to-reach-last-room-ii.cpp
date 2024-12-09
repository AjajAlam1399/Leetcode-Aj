class Solution {
    using vec = vector<int>;
    vector<vector<int>> direction = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<vec, vector<vec>, greater<vec>> pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, 1, 0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int time = it[0];
            int currmove = it[1];
            int i = it[2];
            int j = it[3];

            for (int k = 0; k < 4; k++) {
                int newi = direction[k][0] + i;
                int newj = direction[k][1] + j;

                if (newi >= 0 && newj >= 0 && newi < n && newj < m) {
                    int nexttime=time;
                    if (nexttime<moveTime[newi][newj]) {
                        nexttime=moveTime[newi][newj];
                    } 
                    nexttime+=currmove;
                    if (dist[newi][newj] > nexttime) {
                            dist[newi][newj] = nexttime;
                            if (currmove == 1) {
                                pq.push({nexttime, 2, newi, newj});
                            } else {
                                pq.push({nexttime, 1, newi, newj});
                            }
                        }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
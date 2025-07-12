class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx == sx) return (ty - sy) % sx == 0;
            if (ty == sy) return (tx - sx) % sy == 0;

            if (tx > ty)
                tx %= ty;
            else
                ty %= tx;
        }
        return false;
    }
};

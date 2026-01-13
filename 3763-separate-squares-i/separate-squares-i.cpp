class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        double s = 1e18, e = -1e18;

        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];
            s = min(s, y);
            e = max(e, y + l);
        }

        while (e - s > 1e-5) {
            double mid = (s + e) / 2.0;

            auto res = find(squares, mid);

            if (res[0] < res[1]) {
                s = mid;
            } else {
                e = mid;
            }
        }

        return s;
    }

    vector<double> find(vector<vector<int>>& squares, double mid) {

        double left = 0.0, right = 0.0;

        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];
            double newY = y + l;

            if (y >= mid) {
                right += l * l;
            }
            else if (newY <= mid) {
                left += l * l;
            }
            else {
                double upper = newY - mid;
                double lower = mid - y;
                right += upper * l;
                left  += lower * l;
            }
        }

        return {left, right};
    }
};

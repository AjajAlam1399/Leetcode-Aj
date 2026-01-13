class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();

        double  s=1000000000.0;
        double e =0;

        for(int i=0;i<n;i++){
            double newy=(double)squares[i][1]+(double)squares[i][2];
            double y = squares[i][1];
            s=min(s,y);
            e = max(e,newy);
        }

        double ans = 0.0;

        while(e-s>1e-5){
            double mid = (s+e)/2.0;

            auto res = find(squares,mid);
            if(res[0]<res[1]){
                s=mid;
            }
            else{
                e=mid;
            }
        }

        return s;
    }

    vector<double> find(vector<vector<int>>& squares , double mid){
        double left = 0.0;
        double right=0.0;

        for(int i=0;i<squares.size();i++){
            int x = squares[i][0];
            double y=(double)squares[i][1];
            double l = (double)squares[i][2];

            double newY=y+l;

            if(y>=mid){
                right+=l*l;
            }
            else if(newY>mid && mid>y){
                double ub = newY-mid;
                double lb = mid-y;
                right+=ub*l;
                left+=lb*l;
            }
            else if(newY<=mid){
                left+=l*l;
            }
        }

        return {left,right};
    }
};
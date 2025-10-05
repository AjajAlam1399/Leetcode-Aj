class Solution {
public:
    int stoneGameVI(vector<int>& A, vector<int>& B) {
        
        vector<pair<int,int>>vec;

        int n=A.size();

        for(int i=0;i<n;i++){
            vec.push_back({A[i]+B[i],i});
        }

        sort(vec.rbegin(),vec.rend());

        int a=0,b=0;

        for(int i=0;i<n;i++){
            if(i%2==0){
                a+=A[vec[i].second];
            }
            else{
                b+=B[vec[i].second];
            }
        }

        return a==b?0:a>b?1:-1;
    }
};
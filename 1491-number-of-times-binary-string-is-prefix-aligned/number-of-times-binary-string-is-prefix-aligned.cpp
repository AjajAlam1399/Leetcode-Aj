class Solution {
    vector<int>bit;
    int N;
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n=flips.size();
        N=n+1;
        bit.resize(N);
        int ans=0;
        for(int i=0;i<n;i++){
            int ind=flips[i];
            update(ind);
            int curr=get(i+1);
            // cout<<curr<<endl;
            // int pfsum=((i+1)*(i+2))/2;
            if(curr==i+1){
                ans++;
            }
        }

        return ans;
    }

    void update(int ind){

        while(ind<N){
            bit[ind]+=1;
            ind+=(ind&(-ind));
        }
    }

    int get(int ind){
        int sum=0;

        while(ind>0){
            sum+=bit[ind];
            ind-=(ind&(-ind));
        }
        return sum;
    }
};
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=1;
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;

        while(s<=e){
            int mid=(s+e)/2;
            if(valid(bloomDay,m,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }

    bool valid(vector<int>& bloomDay,int m,int k,int mid){
        int n=bloomDay.size();
        int cnt=0;
        int conscnt=0;

        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                conscnt++;
            }
            else{
                conscnt=0;
            }
            if(conscnt==k){
                cnt++;
                conscnt=0;
            }
        }
        return cnt>=m;
    }
};
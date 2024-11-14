class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int size=quantities.size();
        int l=0,h=0;
        h=*max_element(quantities.begin(),quantities.end());
        int ans=h;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(n,quantities,mid)){
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }

    bool check(int n,vector<int>&quantities,int mid){
        int s=0,size=quantities.size();
        int curr=quantities[s];
        while(n){
            if(curr>mid){
                curr-=mid;
            }
            else{
                s++;
                curr=s<size?quantities[s]:0;
            }
            n--;
        }
        if(s<size || curr!=0)return false;
        return true;
    }
};
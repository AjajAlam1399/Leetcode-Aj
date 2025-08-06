class Solution {
    int n;
    vector<int>seg;
    void insert(int node,int left,int right,int ind,int val){
        if(left==right){
            seg[node]=val;
            return;
        }

        int mid=(left+right)/2;
        if(ind<=mid){
            insert(2*node+1,left,mid,ind,val);
        }
        else{
            insert(2*node+2,mid+1,right,ind,val);
        }
        seg[node]=max(seg[2*node+1],seg[2*node+2]);
    }

    int query(int node,int l,int r,int s,int e){
        if(l>e || r<s){
            return -1;
        }
        if(l>=s && r<=e){
            return seg[node];
        }
        int mid=(l+r)/2;
        return max(query(2*node+1,l,mid,s,e),query(2*node+2,mid+1,r,s,e));
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this->n=fruits.size();
        seg.resize(4*n,-1);
        for(int i=0;i<n;i++){
            insert(0,0,n-1,i,baskets[i]);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int s=0,e=n;
            while(s<e){

                int mid=(s+e)/2;
                if(query(0,0,n-1,s,mid)>=fruits[i]){
                    e=mid;
                }
                else{
                    s=mid+1;
                }
            }
            if(s!=n){
                ans++;
                insert(0,0,n-1,s,-1);
            }
        }
        return n-ans;
    }
};
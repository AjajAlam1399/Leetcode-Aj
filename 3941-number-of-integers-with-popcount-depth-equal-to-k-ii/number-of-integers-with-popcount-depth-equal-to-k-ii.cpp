class Solution {
    using ll=long long;
    ll popCnt(ll num){
        ll ans=0;
        ll temp=num;

        while(temp>1){
            ll bitsCnt=0;

            for(ll i=0;i<64;i++){
                bitsCnt += ((temp >> i) & 1)!=0;
            }
            temp=bitsCnt;
            ans++;
        }
        return ans;
    }
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        ll n=nums.size();

        vector<ll>vec(n,0);

        ll blockSize=(ll)sqrt(n+0.0)+1;

        ll noOfBlock = (n + blockSize - 1) / blockSize;

        vector<vector<ll>>blockArr(blockSize,vector<ll>(6,0));

        for(ll i=0;i<n;i++){
            vec[i]=popCnt(nums[i]);
            if(vec[i]>5){
                continue;
            }
            blockArr[i/blockSize][vec[i]]++;
        }

        vector<int>ans;

        for(int i=0;i<queries.size();i++){
            ll type=queries[i][0];

            if(type==2){
                ll idx=queries[i][1];
                ll val=queries[i][2];
                ll cnt=popCnt(val);
                if(cnt>5){
                    if(vec[idx]<=5){
                        blockArr[idx/blockSize][vec[idx]]--;
                    }
                    vec[idx]=cnt;
                }
                else{
                    if(vec[idx]<=5){
                        blockArr[idx/blockSize][vec[idx]]--;
                        vec[idx]=cnt;
                        blockArr[idx/blockSize][vec[idx]]++;
                    }
                    else{
                        vec[idx]=cnt;
                        blockArr[idx/blockSize][vec[idx]]++;
                    }
                }
            }
            else{
                ll l=queries[i][1];
                ll r=queries[i][2];
                ll k=queries[i][3];
                
                ll startBlock=l/blockSize;
                ll endBlock= r/blockSize;
                int cnt=0;
                if(startBlock==endBlock){
                    for(int i=l;i<=r;i++){
                        if(vec[i]==k){
                            cnt++;
                        }
                    }
                }
                else{
                    for(int i=l;i<(startBlock+1)*blockSize;i++){
                        if(vec[i]==k){
                            cnt++;
                        }
                    }
                    for(int b=startBlock+1;b<endBlock;b++){
                        cnt+=blockArr[b][k];
                    }
                    for(int i=endBlock*blockSize;i<=r;i++){
                        if(vec[i]==k){
                            cnt++;
                        }
                    }
                }

                ans.push_back(cnt);
            }
        }

        return ans;
    }
};
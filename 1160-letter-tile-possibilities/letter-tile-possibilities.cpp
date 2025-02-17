class Solution {
    using ll=long long;
public:
    int numTilePossibilities(string tiles) {
        unordered_map<ll,ll>map;
        int n=tiles.size();
        ll cnt=1;
        map[cnt]=1;
        for(int i=2;i<=n;i++){
            cnt*=i;
            map[i]=cnt;
        }

        unordered_map<char,ll>charMap;
        for(int i=0;i<n;i++){
            charMap[tiles[i]]++;
        }

        vector<int>vec;
        for(auto it : charMap){
            vec.push_back(it.second);
        }

        ll ans=0;
        
        for(int i=n;i>=1;i--){
            fun(0,n-i,map,vec,ans);
        }
        return ans;
    }

    void fun(int ind,int rem,unordered_map<ll,ll>&map,
    vector<int>&vec,ll &ans){
        if(ind==vec.size()){
            if(rem==0){
                ll divide=1;
                ll cnt=0;
                for(auto it : vec){
                    if(it>1){
                        divide*=map[it];
                    }
                    cnt+=it;
                }
                ans+=map[cnt]/divide;
                return ;
            }
            return ;
        }
        fun(ind+1,rem,map,vec,ans);
        if(rem>0 && vec[ind]>=1){
            vec[ind]--;
            fun(ind,rem-1,map,vec,ans);
            vec[ind]++;
        }
        return ;
    }
};
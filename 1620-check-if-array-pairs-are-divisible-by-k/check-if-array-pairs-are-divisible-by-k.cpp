class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size(),cnt=0;

        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            int mod=arr[i]%k;
            if(mod<0){
                mod+=k;
            }
            if(mod==0){
                if(map[mod]){
                    cnt++;
                    if(map[mod]==1){
                        map.erase(mod);
                    }
                    else{
                        map[mod]--;
                    }
                }
                else{
                    map[mod]++;
                }
                continue;
            }
            if(map.find(k-mod)!=map.end()){
                cnt++;
                if(map[k-mod]==1){
                    map.erase(k-mod);
                }
                else{
                    map[k-mod]--;
                }
            }
            else{
                map[mod]++;
            }
        }
        return cnt*2==n;
    }
};
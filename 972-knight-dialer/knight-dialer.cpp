class Solution {
    int mod=1e9+7;
    using ll=long long;
public:
    int knightDialer(int n) {
        vector<vector<int>>graph(10);
        graph[0]={4,6};
        graph[1]={6,8};
        graph[2]={7,9};
        graph[3]={4,8};
        graph[4]={0,3,9};
        graph[6]={0,1,7};
        graph[7]={2,6};
        graph[8]={1,3};
        graph[9]={2,4};
        unordered_map<string,int>map;
        ll ans=0;
        for(int i=0;i<10;i++){
            ans=(ans%mod+fun(i,1,n,graph,map)%mod)%mod;
        }

        return ans;

    }

    int fun(int prev,int level,int n,vector<vector<int>>&graph,unordered_map<string,int>&map){
        if(level==n){
            return 1;
        }
        string str="";
        str+=to_string(prev)+"#"+to_string(level);
        if(map.find(str)!=map.end()){
            return map[str];
        }
        int ans=0;
        for(auto adjnode : graph[prev]){
            ans=(ans%mod+fun(adjnode,level+1,n,graph,map)%mod)%mod;
        }
        string str1="";
        str1+=to_string(prev)+"#"+to_string(level);
        map[str1]=ans;
        return ans;
    }
};
class Solution {
    using ll=long long;
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        ll n=flowers.size();

        map<ll,ll>map;

        for(auto it:flowers){
            map[it[0]]++;
            map[it[1]+1]--;
        }
        ll np=people.size();
        vector<vector<ll>>vec;

        vector<int>ans(np);

        for(ll i=0;i<np;i++){
            vec.push_back({people[i],i});
        }

        sort(vec.begin(),vec.end());

        ll i=0,sum=0;
        for(auto it : map){
            sum+=it.second;
            if(it.first<vec[i][0]){
                    ans[vec[i][1]]=sum;
            }
            else if(it.first==vec[i][0]){

                while(i<np && it.first==vec[i][0]){
                    ans[vec[i][1]]=sum;
                    i++;
                }
            }
            else{
                while(i<np && it.first>vec[i][0]){
                    ans[vec[i][1]]=sum-it.second;
                    i++;
                }
                if(i<np){
                    if(it.first<vec[i][0]){
                        ans[vec[i][1]]=sum;
                    }
                    else{
                       while(i<np && it.first==vec[i][0]){
                            ans[vec[i][1]]=sum;
                            i++;
                        }
                    }
                }
            }
            if(i==np)break;
        }

        return ans;


    }
};
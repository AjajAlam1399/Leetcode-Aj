class Solution {
    using ll=long long;
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int>set;

        int ans=1;
        ll num=1;
        set.insert(1);
        while(num%k!=0){
            num=num%k;
            num*=10;
            num+=1;
            if(set.find(num)!=set.end())return -1;
            set.insert(num);
            ans++;
        }

        return ans;
    }
};
class Solution {
    using pp=pair<int,int>;
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<pp>set;
        int n=rolls.size();

        for(int i=1;i<=k;i++){
            set.insert({0,i});
        }
        vector<int>vec(k+1,0);

        for(int i=n-1;i>=0;i--){
            int mn=set.begin()->first;
            set.erase({vec[rolls[i]],rolls[i]});
            vec[rolls[i]]=mn+1;
            set.insert({vec[rolls[i]],rolls[i]});
        }
        return set.begin()->first+1;
    }
};
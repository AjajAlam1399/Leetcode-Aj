class Solution {
    using ll=long long;
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int i=0,j=n-1;
        int sum=0;
        ll ans=0;

        while(i<j){
            int currsum=skill[i]+skill[j];
            if(sum==0){
                sum=currsum;
            }
            else {
                if(sum!=currsum)return -1;
            }
            ans+=(ll)skill[i]*(ll)skill[j];
            i++;
            j--;
        }
        return ans;
    }
};
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());

        int ans=0;
        int i=0,j=n-1;

        while(i<=j){
            if(i==j){
                ans++;
                i++;
                j--;
            }
            else{
                if(people[j]+people[i]<=limit){
                    ans++;
                    i++;
                    j--;
                }
                else{
                    ans++;
                    j--;
                }
            }
        }

        return ans;

    }
};
bool cmp(int a,int b){return a>b;}
class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>vec(26,0);

        for(int i=0;i<n;i++){
            vec[word[i]-'a']++;
        }

        sort(vec.rbegin(),vec.rend());

        // for(int i=0;i<26;i++)cout<<vec[i]<<" ";
        int cnt=0;
        long long ans=0;

        for(int i=0;i<26;i++){
            int currcnt=vec[i];
            if(currcnt){
                ans+=((cnt/8)+1)*currcnt;
                cnt++;
            }
        }

        return ans;

    }
};
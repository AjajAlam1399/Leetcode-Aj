class Solution {
    using ll=long long ;
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        sort(timePoints.begin(),timePoints.end());
        ll ans=INT_MAX;
        for(int i=1;i<timePoints.size();i++){
            string prevstr=timePoints[i-1];
            string currstr=timePoints[i];
            ll prevH=(prevstr[0]-'0')*10 + prevstr[1]-'0';
            ll prevM=(prevstr[3]-'0')*10 + prevstr[4]-'0';
            ll currH=(currstr[0]-'0')*10 + currstr[1]-'0';
            ll currM=(currstr[3]-'0')*10 + currstr[4]-'0';
            ll prevInMin=60*prevH+prevM;
            ll currInMin=60*currH+currM;
            ll currans=abs(prevInMin-currInMin);
            ans=min(ans,min(currans,1440-currans));
        }
        string prevstr=timePoints[0];
            string currstr=timePoints[n-1];
            ll prevH=(prevstr[0]-'0')*10 + prevstr[1]-'0';
            ll prevM=(prevstr[3]-'0')*10 + prevstr[4]-'0';
            ll currH=(currstr[0]-'0')*10 + currstr[1]-'0';
            ll currM=(currstr[3]-'0')*10 + currstr[4]-'0';
            ll prevInMin=60*prevH+prevM;
            ll currInMin=60*currH+currM;
            ll currans=abs(prevInMin-currInMin);
            ans=min(ans,min(currans,1440-currans));
        return ans;
    }
};
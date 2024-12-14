class Solution {
public:
    long long continuousSubarrays(vector<int>& a) {
        multiset<int> s;
        long long ans=0;
        for (int i=0, j=0; i<a.size(); ++i) {
            s.insert(a[i]);
            while(*s.rbegin()-*s.begin()>2){
                s.erase(s.find(a[j++]));
            }
            ans+=i-j+1;
        }
        return ans;
    }
};
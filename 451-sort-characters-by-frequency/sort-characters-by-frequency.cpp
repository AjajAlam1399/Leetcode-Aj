class cmp{
    public:
     bool operator()(pair<int,char>p1,pair<int,char>p2){
        return p1.first>p2.first;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
      vector<pair<int,char>>vec(256); 

      for(int i=0;i<n;i++){
          int ind=(int)s[i];
          vec[ind].first++;
          vec[ind].second=s[i];
      } 
      sort(vec.begin(),vec.end(),cmp());
      string ans="";
      for(int i=0;i<256;i++){
        //   cout<<vec[i].first<<" "<<vec[i].second<<endl;
        if(vec[i].first==0)break;
          if(vec[i].first!=0){
              string st="";
              for(int j=1;j<=vec[i].first;j++){
                  st+=vec[i].second;
              }
              ans+=st;
          }
      }

      return ans;
    }
};
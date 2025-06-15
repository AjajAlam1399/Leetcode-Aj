class Solution {
public:
    int maxDiff(int num) {
        int dig=log10(num)+1;
        vector<int>vec(dig);
        unordered_map<int,vector<int>>map;

        int n=num,ind=dig-1;

        while(n){
            int val=n%10;
            n/=10;
            vec[ind]=val;
            map[val].push_back(ind);
            ind--;
        }

        

        int minVal=num,maxVal=num;
         vector<int>curr;
        for(auto it : map){
            int digit=it.first;
            
            for(int i=0;i<=9;i++){
                bool flag=true;
                curr=vec;
                for(auto ind:it.second){
                    if(ind==0 && i==0){
                        flag=false;
                        break;
                    }
                    // cout<<digit<<" "<<ind<<" "<<i<<" ";
                    curr[ind]=i;
                }
                if(flag){
                    int val=0;
                    for(int j=0;j<curr.size();j++){
                        val=val*10+curr[j];
                    }
                    // cout<<val<<endl;
                    minVal=min(minVal,val);
                    maxVal=max(maxVal,val);
                }
            }
        }

        // cout<<maxVal<<endl;
        // cout<<minVal<<endl;

        return maxVal-minVal;
    }
};
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>map1,map2,swaps;

        int ans=INT_MAX,n=tops.size();

        for(int i=0;i<tops.size();i++){
            if(tops[i]==bottoms[i]){
                map1[tops[i]]++;
                swaps[tops[i]]++;
            }
            else{
                map1[tops[i]]++;
                map2[bottoms[i]]++;
            }
        }

        for(auto it : map1){
            int key=it.first;
            int val1=it.second;
            int less=swaps[key];

            int val2=map2[key];

            if(val1+val2>=n){
                if(val1>=n || val2>=n){
                    return 0;
                }
                else{
                    ans=min(ans,n-val1);
                    ans=min(ans,n-val2-less);
                }
            }
        }

        for(auto it : map2){
            int key=it.first;
            int val1=it.second;
            int less=swaps[key];
            int val2=map1[key];

            if(val1+val2>=n){
                if(val1>=n || val2>=n){
                    return 0;
                }
                else{
                    ans=min(ans,n-val1-less);
                    ans=min(ans,n-val2);
                }
            }
        }

        return ans==INT_MAX?-1:ans;

    }
};
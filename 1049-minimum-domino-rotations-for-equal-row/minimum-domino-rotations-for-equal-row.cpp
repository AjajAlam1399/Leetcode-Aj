class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>map1,map2,swaps;

        int ans=INT_MAX,n=tops.size();

        for(int i=0;i<tops.size();i++){
            if(tops[i]==bottoms[i]){
                swaps[tops[i]]++;
            }
            else{
                map1[tops[i]]++;
                map2[bottoms[i]]++;
            }
        }

        for(int i=1;i<=6;i++){
            int req=n-swaps[i];
            int val1=map1[i];
            int val2=map2[i];

            if(val1+val2>=req){
                if(val1>=req || val2>=req)return 0;
                ans=min(ans,req-val1);
                ans=min(ans,req-val2);
            }
        }

        

        return ans==INT_MAX?-1:ans;

    }
};
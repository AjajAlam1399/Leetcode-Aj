class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();

        multiset<vector<int>>set;
        for(int i=0;i<n;i++){
            set.insert({nums[i][0],i,0});
        }
        int len=INT_MAX,anss,anse;

        while(true){
            auto begin=set.begin();
            auto end=set.rbegin();
            int s=(*begin)[0],e=(*end)[0];
            int currlen=e-s;
            if(len>currlen){
                anss=s;
                anse=e;
                len=currlen;
            }
            int i=(*begin)[1],next=((*begin)[2])+1;
            int val;
            if(next>=nums[i].size()){
                break;
            }
            else{
                val=nums[i][next];
            }
            set.erase(begin);
            set.insert({val,i,next});
        }
        return {anss,anse};
    }
};
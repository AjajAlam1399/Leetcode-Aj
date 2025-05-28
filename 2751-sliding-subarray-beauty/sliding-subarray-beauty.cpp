class Solution {

    vector<int>bit;
    void update(int idx,int val){
        
        while(idx<52){
            bit[idx]+=val;
            idx+=idx&(-idx);
        }
    }

    int query(int x){
        int currsum=0,currind=0;

        for(int i=log2(52);i>=0;i--){
            if(currind+(1<<i)<52 && currsum+bit[currind+(1<<i)]<x){
                currind+=(1<<i);
                currsum+=bit[currind];
            }
        }

        return currind+1;
    }
public:
    Solution(){
        bit.resize(52,0);
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        int n=nums.size();

        int i=0,j=0;

        vector<int>ans;

        while(j<n){
           if(nums[j]<0){
            update(51-abs(nums[j]),1);
           } 

           if(j-i+1==k){
            int q=query(x);
            if(q>51)ans.push_back(0);
            else ans.push_back(-1*(51-q));
            if(nums[i]<0){
                update(51-abs(nums[i]),-1);
            }
            i++;
           }
           j++;
        }

        return ans;
    }
};
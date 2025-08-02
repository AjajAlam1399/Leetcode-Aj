class Solution {
    using ll=long long;
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        ll n=nums.size();

        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());

        vector<int>odd,even;

        for(int i=0;i<n;i++){
            if(nums[i]%2){
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }

        ll profit=0,loss=0;
        ll ans=0;
        int o=0,e=0;

        for(int i=0;i<n;i++){
            if(target[i]%2){
                if(odd[o]==target[i]){
                    o++;
                    continue;
                }
                if(odd[o]>target[i]){
                    ll diff=odd[o]-target[i];
                    if(loss){
                        if(loss>=diff){
                            loss-=diff;
                        }
                        else{
                            diff-=loss;
                            loss=0;
                            profit+=diff;
                            ans+=diff/2;
                        }
                    }
                    else{
                            profit+=diff;
                            ans+=diff/2; 
                    }
                }
                else {
                    ll diff=target[i]-odd[o];
                    if(profit){
                        if(profit>=diff){
                            profit-=diff;
                        }
                        else{
                            diff-=profit;
                            profit=0;
                            loss+=diff;
                            ans+=diff/2;
                        }
                    }
                    else{
                            loss+=diff;
                            ans+=diff/2; 
                    }
                }
                o++;
            }
            else{
                if(even[e]==target[i]){
                    e++;
                    continue;
                }
                if(even[e]>target[i]){
                    ll diff=even[e]-target[i];
                    if(loss){
                        if(loss>=diff){
                            loss-=diff;
                        }
                        else{
                            diff-=loss;
                            loss=0;
                            profit+=diff;
                            ans+=diff/2;
                        }
                    }
                    else{
                            profit+=diff;
                            ans+=diff/2; 
                    }
                }
                else {
                    ll diff=target[i]-even[e];
                    if(profit){
                        if(profit>=diff){
                            profit-=diff;
                        }
                        else{
                            diff-=profit;
                            profit=0;
                            loss+=diff;
                            ans+=diff/2;
                        }
                    }
                    else{
                            loss+=diff;
                            ans+=diff/2; 
                    }
                }
                e++;
            }
        }

        return ans;
    }
};
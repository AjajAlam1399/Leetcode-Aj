class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int  n=arr.size();
        vector<pair<string,int>>vec;

        for(int i=0;i<n;i++){
            bool f1=false;
            for(int j=0;j<vec.size();j++){
                if(vec[j].first==arr[i]){
                    f1=true;
                    vec[j].second++;
                    break;
                }
            }
            if(!f1){
                vec.push_back({arr[i],1});
            }
        }
        int c=0;
        for(auto it : vec){
            if(it.second==1){
                c++;
            }
            if(c==k){
                return it.first;
            }
        }
        return "";
    }
};
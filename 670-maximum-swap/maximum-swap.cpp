class Solution {
public:
    int maximumSwap(int num) {
        if(num<=11)return num;
        vector<int>vec;
        while(num){
            int mod=num%10;
            num/=10;
            vec.push_back(mod);
        }
        vector<int>vec2(vec.size());
        int maxval=vec[0];
        vec2[0]=maxval;

        for(int i=1;i<vec.size();i++){
            vec2[i]=max(vec[i],vec2[i-1]);
        }
        for(int i=vec2.size()-1;i>=0;i--){
            if(vec[i]<vec2[i]){
                int val=vec[i];
                vec[i]=vec2[i];
                for(int j=0;j<=i;j++){
                    if(vec[j]==vec2[i]){
                        vec[j]=val;
                        break;
                    }
                }
                break;
            }
        }
        int ans=0;

        for(int i=vec2.size()-1;i>=0;i--){
            ans*=10;
            ans+=vec[i];
        }
        return ans;
    }
};
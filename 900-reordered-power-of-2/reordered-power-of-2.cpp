class Solution {
    using ll=long long ;
public:
    bool reorderedPowerOf2(int n) {
        
        vector<int>vec(10,0);
        int digcnt=0;
        int temp=n;

        while(temp){
            digcnt++;
            vec[temp%10]++;
            temp/=10;
        }

        for(int i=1;i<10;i++){
            if(vec[i]){
                vec[i]--;
                if(fun(1,i,vec,digcnt))return true;
                vec[i]++;
            }
        }
        return false;
    }

    bool fun(int ind,ll curr,vector<int>&vec,int totalDigit){

        if(ind==totalDigit){
            return ((curr)&(curr-1))==0;
        }

        for(int i=0;i<10;i++){
            if(vec[i]){
                vec[i]--;
                if(fun(ind+1,curr*10+i,vec,totalDigit)){
                    return true;
                }
                vec[i]++;
            }
        }
        return false;
    }
};
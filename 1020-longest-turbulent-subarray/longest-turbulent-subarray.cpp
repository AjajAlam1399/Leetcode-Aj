class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size(),i=0;
        int ans=1;

        while(i<n){
            int prev=arr[i];
            int cnt=1;
            int sign=-1;
            int ind=i;
            while(ind+1<n){
                if(sign==-1){
                    if(arr[ind+1]>prev){
                        sign=0;
                        prev=arr[ind+1];
                        ind++;
                        cnt++;
                    }
                    else if(arr[ind+1]<prev){
                        sign=1;
                        prev=arr[ind+1];
                        ind++;
                        cnt++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(sign==1){
                        if(arr[ind+1]>prev){
                            cnt++;
                            sign=0;
                            prev=arr[ind+1];
                            ind++;
                        }
                        else{
                            break;
                        }
                    }
                    else if(sign==0){
                        if(arr[ind+1]<prev){
                            cnt++;
                            prev=arr[ind+1];
                            sign=1;
                            ind++;
                        }
                        else break;
                    }
                }
            }
            ans=max(ans,cnt);
            if(i==ind){
                i++;
            }
            else{
                i=ind;
            }
        }
        return ans;
    }
};
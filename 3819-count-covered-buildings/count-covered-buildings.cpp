class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,vector<int>>x,y;

        for(int i=0;i<buildings.size();i++){
            x[buildings[i][1]].push_back(buildings[i][0]);
            y[buildings[i][0]].push_back(buildings[i][1]);
        }

        for(auto &it: x){
            sort(it.second.begin(),it.second.end());
        }

         for(auto &it : y){
            sort(it.second.begin(),it.second.end());
        }

        int ans=0;

        for(int i=0;i<buildings.size();i++){
            int bx=buildings[i][0];
            int by=buildings[i][1];

            int lx=findLowerCnt(x[by],bx-1);
            int ux=upperCnt(x[by],bx+1);

            if(!lx || !ux)continue;

            int ly=findLowerCnt(y[bx],by-1);
            int uy=upperCnt(y[bx],by+1);

            if(ly && uy){
                ans++;
            }
        }

        return ans;
    }

    int findLowerCnt(vector<int>&vec,int num){
        int ans=-1;
        int s=0,e=vec.size()-1;

        while(s<=e){
            int mid=(s+e)/2;
            if(vec[mid]<=num){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return ans+1;
    }

     int upperCnt(vector<int>&vec,int num){
        int n=vec.size();
        int ans=n;
        int s=0,e=n-1;

        while(s<=e){
            int mid=(s+e)/2;
            if(vec[mid]>=num){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return n-ans;
    }


};
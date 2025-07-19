class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        int n=f.size();

        sort(f.begin(),f.end());

        unordered_set<string>set;

        for(int i=0;i<n;i++){
            string str="";
            int j=0;
            bool flag=true;
            while(j<f[i].size()){
                while(j<f[i].size() && f[i][j]!='/'){
                    str.push_back(f[i][j]);
                    j++;
                }
                if(set.find(str)!=set.end()){
                    flag=false;
                    break;
                }
                str.push_back('/');
                j++;
            }
            if(flag){
                set.insert(f[i]);
            }
        }

        vector<string>ans;

        for(int i=0;i<n;i++){
            if(set.find(f[i])!=set.end()){
                ans.push_back(f[i]);
            }
        }

        return ans;
    }
};
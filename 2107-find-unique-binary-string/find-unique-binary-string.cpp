class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n=nums.size();
        int m=nums[0].size();
        unordered_set<int>set;

        for(int i=0;i<n;i++){
            int num=0;
            for(int j=m-1;j>=0;j--){
                if(nums[i][j]=='1'){
                    int ind=m-1-j;
                    num=(num|(1<<ind));
                }
            }
            cout<<num<<endl;
            set.insert(num);
        }
        int cnt=0;

        while(true){
            if(set.find(cnt)==set.end()){
                break;
            }
            cnt++;
        }
        string ans="";
        for(int i=16;i>=0;i--){
            int bit=(cnt&(1<<i));
            if(bit){
                ans+='1';
            }
            else{
                ans+='0';
            }
        }
        if(ans.size()>n){
            int len=ans.size()-n;
            ans=ans.substr(len);
        }

        return ans;

    }
};
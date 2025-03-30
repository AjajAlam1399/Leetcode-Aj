class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>map;

        for(int i=0;i<s.size();i++){
            map[s[i]]=i;
        }
        int cnt=1;
        vector<int>ans;
        int last=map[s[0]] , i=0;

        while(i<s.size()){

            if(i==last){
                ans.push_back(cnt);
                cnt=1;
                i++;
                if(i==s.size())break;
                last=map[s[i]];
            }
            else{
                i++;
                if(i==s.size()){
                    break;
                }
                last=max(last,map[s[i]]);
                cnt++;
            }
        }
        return ans;
    }
};
class Solution {
    bool static cmp(int a, int b) {
        string vec1="";
        string vec2="";
        for (int i = 31; i >= 0; i--) {
            int bit = (a & (1 << i));
            if (bit) {
                vec1+="1";
            } else {
                if (vec1.size() > 0) {
                    vec1+="0";
                }
            }
             bit = (b & (1 << i));
            if (bit) {
                vec2+="1";
            } else {
                if (vec2.size() > 0) {
                    vec2+="0";
                }
            }
        }
        string ab=vec1+vec2;
        string ba=vec2+vec1;

        return ab>ba;
        
    }

public:
    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string a="";
        string b="";
        string c="";
        for (int i = 31; i >= 0; i--) {
            int bit = (nums[0] & (1 << i));
            if (bit) {
                a+="1";
            } else {
                if (a.size() > 0) {
                    a+="0";
                }
            }
             bit = (nums[1] & (1 << i));
            if (bit) {
                b+="1";
            } else {
                if (b.size() > 0) {
                    b+="0";
                }
            }
             bit = (nums[2] & (1 << i));
            if (bit) {
                c+="1";
            } else {
                if (c.size() > 0) {
                    c+="0";
                }
            }
        }

        string abc=a+b+c;
        // cout<<abc;
        int ans=0;
        for(int i=abc.size()-1;i>=0;i--){
            if(abc[i]=='1'){
                ans=ans|(1<<(abc.size()-1-i));
            }
        }
        return ans;
        
    }
};
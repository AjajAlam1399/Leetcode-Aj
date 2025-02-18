class Solution {
public:
    string smallestNumber(string pattern) {
        string ans="";
        int bitMask=0;

        for(int i=1;i<=9;i++){
            ans.push_back(i+'0');
            bitMask|=(1<<i);
            if(fun(0,bitMask,pattern,ans)){
                break;
            }
            ans.pop_back();
            bitMask=(bitMask)&(~(1<<i));
        }
        return ans;
    }
    bool fun(int ind,int &bitMask,string &pattern,string &ans){
        if(ind==pattern.size()){
            return true;
        }
        for(int i=1;i<=9;i++){
            int bit=(bitMask)&(1<<i);
            if(!bit){
                if((pattern[ind]=='I' && i>(ans.back()-'0'))||
                (pattern[ind]=='D' && i<(ans.back()-'0'))){
                    ans.push_back('0'+i);
                    bitMask|=(1<<i);
                    if(fun(ind+1,bitMask,pattern,ans)){
                        return true;
                    }
                    ans.pop_back();
                    bitMask=(bitMask)&(~(1<<i));
                }
            }
        }
        return false;
    }
};
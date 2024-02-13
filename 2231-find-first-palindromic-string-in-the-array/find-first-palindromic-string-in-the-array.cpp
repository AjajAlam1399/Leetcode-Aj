class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(auto str : words){
            if(check(str)){
                ans=str;
                break;
            }
        }
        return ans;
    }

    bool check(string str){
        int i=0;
        int j=str.size()-1;

        while(i<j){
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }
};
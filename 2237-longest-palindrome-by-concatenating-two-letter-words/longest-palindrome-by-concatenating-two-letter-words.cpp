class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();

        unordered_map<string,int>similar,diffrent;

        for(int i=0;i<n;i++){
            char ch1=words[i][0],ch2=words[i][1];

            if(ch1==ch2)similar[words[i]]++;
            else{
                diffrent[words[i]]++;
            }
        }
        int cnt=0;
        bool oddtaken=false;

        for(auto it : similar){
            int currcnt=it.second;
            if(currcnt%2!=0){
                cnt+=(currcnt-1);
                if(!oddtaken){
                    cnt++;
                    oddtaken=true;
                }
            }
            else{
                cnt+=currcnt;
            }
        }


        for(int i=0;i<n;i++){
            if(diffrent.find(words[i])!=diffrent.end()){
                char ch1=words[i][0],ch2=words[i][1];
                string str1=words[i];
                string str2="";
                str2.push_back(ch2);
                str2.push_back(ch1);
                cnt+=min(diffrent[str1],diffrent[str2])*2;
                diffrent.erase(str1);
            }
        }

        return cnt*2;
    }
};
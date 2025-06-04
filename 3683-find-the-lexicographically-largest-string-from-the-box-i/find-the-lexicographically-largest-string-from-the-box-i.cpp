class Solution {
public:
    string answerString(string word, int numFriends) {

        if(numFriends==1)return word;
        int n=word.size();
        int k=n+1-numFriends;

        string str=word.substr(0,k);

        for(int i=1;i<n;i++){
            int len=min(k,n-i);
            string currstr=word.substr(i,len);
            str=check(str,currstr);
        }

        return str;
    }

    string check(string &str1,string& str2){
        int len=min(str1.size(),str2.size());

        for(int i=0;i<len;i++){
            int ind1=str1[i]-'a';
            int ind2=str2[i]-'a';
            if(ind1>ind2)return str1;
            else if(ind1<ind2) return str2;
        }

        return str1.size()>=str2.size()?str1:str2;
    }
};
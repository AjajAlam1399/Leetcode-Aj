class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n1=sentence.size(),n2=searchWord.size();
        int i=0,j=0;
        int index=1;
        while(i<n1){
            bool flag=true;
            while(i<n1 && sentence[i]!=' '){
                if(flag){
                    if(j<n2 && sentence[i]==searchWord[j]){
                        i++;
                        j++;
                    }
                    else{
                        flag=false;
                    }
                }
                else{
                    i++;
                }
            }
            if(j==n2)return index;
            j=0;
            if(i<n1 && sentence[i]==' '){
                index++;
            }
            i++;
        }
        return -1;
    }
};
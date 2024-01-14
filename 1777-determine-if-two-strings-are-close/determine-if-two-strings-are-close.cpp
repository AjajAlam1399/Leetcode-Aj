class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int  n1=word1.size();
        int n2=word2.size();

        if(n1!=n2)return false;
        vector<int>vec1(26,0);
        vector<int>vec2(26,0);
        
        for(int i=0;i<n1;i++){
            vec1[word1[i]-'a']++;
            vec2[word2[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if((vec1[i]!=0 && vec2[i]==0)||(vec2[i]!=0 && vec1[i]==0)) return false;
        }

        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        for(int i=0;i<26;i++){
            map1[vec1[i]]++;
            map2[vec2[i]]++;
        }
        for(int i=0;i<26;i++){
            if(map1[vec1[i]]!=map2[vec1[i]])return false;
        }
        return true;
    }
};
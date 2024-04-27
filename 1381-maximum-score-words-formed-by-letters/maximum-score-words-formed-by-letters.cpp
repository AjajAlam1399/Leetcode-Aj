class Solution {
    using ll=long long;
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>map;
        for(int i=0;i<letters.size();i++){
            map[letters[i]]++;
        }
        return fun(0,words,map,score);
    }

    ll fun(int ind,vector<string>& words,unordered_map<char,int>&map,vector<int>& score){
        if(ind==words.size())return 0;

        ll not_taken=fun(ind+1,words,map,score);
        ll taken=0;
        ll value=isValid(words[ind],map,score);
        if(value){
            taken=value+fun(ind+1,words,map,score);
            insert(words[ind],map);
        }
        return max(taken,not_taken);
    }
    ll isValid(string word,unordered_map<char,int>&map,vector<int>& score){
        int ind=0;
        ll value=0;
        while(ind<word.size()){
            if(map.find(word[ind])==map.end()){
                for(int i=0;i<ind;i++){
                    map[word[i]]++;
                }
                return 0;
            }
            else{
                value+=score[word[ind]-'a'];
                if(map[word[ind]]==1){
                    map.erase(word[ind]);
                }
                else{
                    map[word[ind]]--;
                }
            }
            ind++;
        }
        return value;
    }
    void insert(string word,unordered_map<char,int>&map){
        for(int i=0;i<word.size();i++){
            map[word[i]]++;
        }
    }
};
class Solution {
    using ll=long long;
public:
    long long countOfSubstrings(string word, int k) {
        ll n=word.size();
        ll i=-1,j1=-1,j2=-1,cnt1=0,cnt2=0,ans=0;
        unordered_map<char,int>map;

        while(true){
            bool f1=false,f2=false,f3=false;
            while(j2<n && cnt2<k+1){
                f1=true;
                j2++;
                if(!isVowel(word[j2])){
                    cnt2++;
                }
                
                if(cnt2==k+1){
                    break;
                }
            }
            while(j1<j2){
                f2=true;
                j1++;
                if(isVowel(word[j1])){
                    map[word[j1]]++;
                }
                else{
                    cnt1++;
                }
                if(cnt1==k && map.size()==5){
                    break;
                }
            }
            while(i<j1){
                f3=true;
                i++;
                if(cnt1==k && map.size()==5){
                    ans+=j2-j1;
                    // cout<<j2<<","<<j1<<"-"<<j2-j1<<endl;
                }
                if(isVowel(word[i])){
                    if(map[word[i]]==1){
                        map.erase(word[i]);
                    }
                    else{
                        map[word[i]]--;
                    }
                }
                else{
                    cnt1--;
                    cnt2--;
                }
                if(cnt1<k || map.size()<5){
                    break;
                }

            }
            if(!f1 && !f2 && !f3){
                break;
            }
        }
        return ans;
    }
    bool isVowel(char ch){
        if(ch=='a' || ch=='e'|| ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
};
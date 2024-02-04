class Solution {
public:
    string minWindow(string S, string t) {
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        int n1=t.size();
        int n2=S.size();
        for(int i=0;i<n1;i++){
            map1[t[i]]++;
        }
        int s=-1,e=-1,len=1e7;
        int i=-1,j=-1;
        int cnt=0;
        while(true){
            bool f1=false;
            bool f2=false;
            while(i<n2-1){
                f1=true;
                i++;
                if(map1.find(S[i])!=map1.end() && map2[S[i]]<map1[S[i]]){
                    cnt++;
                }
                map2[S[i]]++;
                if(cnt==n1){
                    break;
                }
            }

            while(j<i){
                f2=true;
                j++;
                if(cnt==n1){
                    int currlen=i-j+1;
                    if(len>currlen){
                        len=currlen;
                        s=j;
                        e=i;
                    }
                }

                if(map1.find(S[j])!=map1.end()){
                    if(map2[S[j]]<=map1[S[j]]){
                        cnt--;
                    }
                }
                erase(S[j],map2);
                if(cnt<n1){
                    break;
                }

            }
            if(!f1 && !f2)break;
        }
        return len==1e7?"":S.substr(s,e-s+1);
    }

    void erase(char ch,unordered_map<char,int>&map){
        if(map[ch]==1){
            map.erase(ch);
        }
        else{
            map[ch]--;
        }
    }
};
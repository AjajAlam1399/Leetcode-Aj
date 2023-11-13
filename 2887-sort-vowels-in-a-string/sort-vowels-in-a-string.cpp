class Solution {
public:
    string sortVowels(string s) {
        
        map<pair<int,int>,int>map;
        
        deque<int>dq;
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                int ind=(int)s[i];
                map[{ind,s[i]}]++;
                dq.push_back(i);
            }
        }
        if(dq.empty()) return s;
        
        while(!dq.empty()){
            int ind=dq.front();
            dq.pop_front();
            
            auto mapel=map.begin();
            
            s[ind]=mapel->first.second;
            
            if(mapel->second==1){
                map.erase(map.begin());
            }
            else {
                map[{mapel->first.first,mapel->first.second}]--;
            }
        }
        
        return s;
        
        
    }
    
    bool isVowel(char ch){
        if(ch=='a'|| ch=='A' || ch=='e' || ch=='E' || ch=='i'|| ch=='I' ||ch=='o' || ch=='O' || ch=='U' ||  ch=='u')return true;
        
        return false;
    }
};
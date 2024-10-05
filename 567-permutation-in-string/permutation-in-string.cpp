class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>vec1(26);
        int n1=s1.size(),n2=s2.size();

        for(int i=0;i<n1;i++){
            vec1[s1[i]-'a']++;
        }

        int s=0,e=0;
        vector<int>vec2(26,0);
        while(e<n2){
            if(e-s+1<n1){
                vec2[s2[e]-'a']++;
            }
            else if(e-s+1==n1){
                vec2[s2[e]-'a']++;
                if(vec1==vec2)return true;
                vec2[s2[s]-'a']--;
                s++;
            }
            e++;
        }
        return false;
    }
};
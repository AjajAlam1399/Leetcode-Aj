class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>vec;
        unordered_map<int,int>map;
        int cnt=0;

        for(int i=0;i<A.size();i++){
            if(map.find(A[i])!=map.end()){
                cnt++;
            }
            else{
                map[A[i]]++;
            }

            if(map.find(B[i])!=map.end()){
                cnt++;
            }
            else{
                map[B[i]]++;
            }
            vec.push_back(cnt);
        }

        return vec;
    }
};

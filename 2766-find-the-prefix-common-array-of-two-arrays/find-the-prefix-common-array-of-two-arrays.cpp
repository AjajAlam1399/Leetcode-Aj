class Solution {
    using ll=long long;
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>vec;
        long long bitmask=0;
        int cnt=0;

        for(int i=0;i<A.size();i++){
            ll ind=(ll)A[i];
            ll shift=(ll)pow(2,ind);
            ll bit=bitmask&shift;
            if(bit)cnt++;
            else{
                bitmask|=shift;
            }
            ind=B[i];
            shift=(ll)pow(2,ind);
            bit=bitmask&shift;
            if(bit)cnt++;
            else{
                bitmask|=shift;
            }
            vec.push_back(cnt);
        }

        return vec;
    }
};

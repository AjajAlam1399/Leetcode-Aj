class SQD {
    vector<int> arr;
    vector<int> blockArr;
    vector<int> lazyArr;
    int blockSize;

public:
    SQD(vector<int> arr) {
        this->arr = arr;
        int n = arr.size();
        blockSize = ceil(sqrt(n));
        blockArr.resize(blockSize, 0);
        lazyArr.resize(blockSize, 0);
    }
    void update(int l, int r, int val) {
        int start = l / blockSize;
        int end = r / blockSize;

        if (start == end) {
            for (int i = l; i <= r; i++) {
                arr[i] += val;
                blockArr[start] += val;
            }
        } else {

            for (int i = l; i < (start + 1) * blockSize; i++) {
                arr[i] += val;
                blockArr[start] += val;
            }
            for (int i = start + 1; i < end; i++) {
                lazyArr[i] += val;
            }
            for (int i = end * blockSize; i <= r; i++) {
                arr[i] += val;
                blockArr[end] += val;
            }
        }
    }
    int query(int l, int r) {
        int start = l / blockSize;
        int end = r / blockSize;
        int sum = 0;
        if (start == end) {
            for (int i = l; i <= r; i++) {
                sum += arr[i] + lazyArr[start];
            }
        } else {
            for (int i = l; i < (start + 1) * blockSize; i++) {
                sum += arr[i] + lazyArr[start];
            }
            for (int i = start + 1; i < end; i++) {
                sum += blockArr[i] + lazyArr[i] * blockSize;
            }
            for (int i = end * blockSize; i <= r; i++) {
                sum += arr[i] + lazyArr[end];
            }
        }
        return sum;
    }
};
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> vec(n, 0);
        SQD sd(vec);

        for (auto it : shifts) {
            int val = it[2] == 0 ? -1 : 1;
            sd.update(it[0], it[1], val);
        }

        string ans = "";

         for(int i=0;i<n;i++){
            int val=sd.query(i,i)%26;
            char ch=s[i];
            int add=((ch-'a')+val+26)%26;
            ans.push_back('a'+add);
            
        }

        return ans;
    }
};
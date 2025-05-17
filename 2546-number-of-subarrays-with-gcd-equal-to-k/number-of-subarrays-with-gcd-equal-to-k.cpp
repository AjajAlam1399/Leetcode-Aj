class Solution {
    class ST {
        int maxD, n;
        vector<vector<int>> st;

    public:
        ST(int n) {
            this->n = n;
            maxD = log2(n) + 1;
            st.resize(n, vector<int>(maxD));
        }
        void build(vector<int>& nums) {

            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < maxD; j++) {
                    if (i + (1 << j) - 1 >= n)
                        break;
                    if (!j) {
                        st[i][j] = nums[i];
                    } else{
                        st[i][j] =
                            __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
                    }
                }
            }
        }
        int query(int l, int r) {
            int d = r - l + 1;
            int j = log2(d);
            return __gcd(st[l][j], st[r - (1 << j) + 1][j]);
        }
    };

public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        ST st(n);

        st.build(nums);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int s = i, e = n - 1;
            int lbind = -1;
            
            while (s <= e) {
                int mid = (s + e) / 2;
                int curr = st.query(i, mid);
                if (curr == k) {
                    lbind = mid;
                    s = mid + 1;
                } else if (curr > k) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }

            // cout<<i<<"-"<<lbind<<endl;

            if (lbind != -1) {
                s = i, e = n - 1;
                int ubind = -1;
                int ubindVal=-1;
                while (s <= e) {
                    int mid = (s + e) / 2;
                    int curr = st.query(i, mid);
                    if (curr == k) {
                        ubind = mid;
                        ubindVal=curr;
                        e= mid -1;
                    } else if (curr > k) {
                        ubind = mid;
                        ubindVal=curr;
                        s = mid + 1;
                    } else {
                        e = mid - 1;
                    }
                }
                if(ubindVal==k){
                    ubind--;
                }
                // cout<<i<<"-"<<ubind<<endl;
                ans+=lbind-ubind;
            }
        }

        return ans;
    }
};
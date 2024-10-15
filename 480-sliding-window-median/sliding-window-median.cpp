class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> small; // Max heap (smaller half)
        multiset<int> large; // Min heap (larger half)
        int s = 0, e = 0, n = nums.size();
        vector<double> ans;

        while (e < n) {
            insert(nums[e], small, large);

            if (e - s + 1 == k) {
                // Calculate the median
                double currAns = result(small, large);
                ans.push_back(currAns);

                // Remove the element that's sliding out of the window
                remove(nums[s], small, large);
                s++;
            }
            e++;
        }

        return ans;
    }

    // Insert value into the appropriate heap and rebalance
    void insert(int val, multiset<int>& small, multiset<int>& large) {
        if (small.empty() || val <= *small.rbegin()) {
            small.insert(val);
        } else {
            large.insert(val);
        }
        reBalance(small, large);
    }

    // Remove value from the appropriate heap
    void remove(int val, multiset<int>& small, multiset<int>& large) {
        if (!small.empty() && val <= *small.rbegin()) {
            small.erase(small.find(val));
        } else {
            large.erase(large.find(val));
        }
        reBalance(small, large);
    }

    // Rebalance the heaps
    void reBalance(multiset<int>& small, multiset<int>& large) {
        if (small.size() > large.size() + 1) {
            large.insert(*small.rbegin());
            small.erase(prev(small.end())); // Use iterator to erase specific instance
        } else if (large.size() > small.size()) {
            small.insert(*large.begin());
            large.erase(large.begin()); // Use iterator to erase specific instance
        }
    }

    // Return the median of the current window
    double result(multiset<int>& small, multiset<int>& large) {
        if (small.size() > large.size()) {
            return *small.rbegin(); // Odd number of elements
        }
        return ((double) *small.rbegin() + (double) *large.begin()) / 2.0; // Even number of elements
    }
};
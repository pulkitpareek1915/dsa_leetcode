class Solution {
public:
    void subset(vector<int>& set, vector<int>& ss) {
        int n = set.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += set[i];
                }
            }
            ss.push_back(sum);
        }
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int n1 = n / 2;
        int n2 = n - n1;
        vector<int> set1;
        vector<int> set2;
        vector<int> ss1;
        vector<int> ss2;
        for (int i = 0; i < n1; i++) {
            set1.push_back(nums[i]);
        }
        for (int i = n1; i < n; i++) {
            set2.push_back(nums[i]);
        }
        subset(set1, ss1);
        subset(set2, ss2);
        int m1 = ss1.size();
        int m2 = ss2.size();
        sort(ss2.begin(), ss2.end());
        int ans = INT_MAX;
        for (int i = 0; i < m1; i++) {
            int target = goal - ss1[i];
            auto it = lower_bound(ss2.begin(), ss2.end(), target);
            if (it != ss2.end()) {
                ans=min(ans,abs(ss1[i]+(*it)-goal));
            }
            if(it!=ss2.begin())
            {
                it--;
                ans=min(ans,abs(ss1[i]+(*it)-goal));
            }
            
        }
        return ans;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int d = INT_MAX;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                int dist = abs(target - sum);
                if (dist < d) {
                    d = dist;
                    ans = sum;
                }

                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    return target;
                }
            }
        }

        return ans;
    }
};
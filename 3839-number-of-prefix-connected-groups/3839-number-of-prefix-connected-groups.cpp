class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string, int> mp;

        for (string &word : words) {
            if (word.size() < k)
                continue;

            string pre = word.substr(0, k);
            mp[pre]++;
        }

        int ans = 0;

        for (auto &it : mp) {
            if (it.second >= 2)
                ans++;
        }

        return ans;
    }
};
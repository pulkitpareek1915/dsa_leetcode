class Solution {
public:
    int findTheLongestSubstring(string s) {

        unordered_map<int, int> mp;
        mp[0] = -1;

        int xr = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == 'a')
                xr ^= 2;
            else if (s[i] == 'e')
                xr ^= 4;
            else if (s[i] == 'i')
                xr ^= 8;
            else if (s[i] == 'o')
                xr ^= 16;
            else if (s[i] == 'u')
                xr ^= 32;

            if (mp.count(xr))
                ans = max(ans, i - mp[xr]);
            else
                mp[xr] = i;
        }

        return ans;
    }
};
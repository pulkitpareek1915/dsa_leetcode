class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            string temp=strs[i];
            string org=temp;
            sort(temp.begin(),temp.end());
            map[temp].push_back(org);
        }
        vector<vector<string>> ans;
        for(auto it:map)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
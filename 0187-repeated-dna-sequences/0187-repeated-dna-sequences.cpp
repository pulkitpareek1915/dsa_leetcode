class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> map;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            map[s.substr(i,10)]++;
        }
        vector<string> ans;
        for(auto it:map)
        {
            if(it.second>=2)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        int n=words1.size();
        for(int i=0;i<n;i++)
        {
            m1[words1[i]]++;
        }
        int m=words2.size();
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            m2[words2[i]]++;
        }
        for(string s:words1)
        {
            if(m1[s]==1&&m2[s]==1) cnt++;
        }
        return cnt;
    }
};
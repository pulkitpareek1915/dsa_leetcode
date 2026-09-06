class Solution {
public:
    bool solve(int index,string& s,unordered_set<string> &st,vector<int> &dp)
    {
        if(index==s.size())
        {
            return true;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        string temp="";
        for(int j=index;j<s.size();j++)
        {
            temp+=s[j];
            if(st.count(temp))
            {
                if(solve(j+1,s,st,dp))
                {
                    return dp[index]=true;
                }
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_set<string> st(wordDict.begin(),wordDict.end());
       vector<int> dp(s.size(),-1);
       return solve(0,s,st,dp); 
    }
};
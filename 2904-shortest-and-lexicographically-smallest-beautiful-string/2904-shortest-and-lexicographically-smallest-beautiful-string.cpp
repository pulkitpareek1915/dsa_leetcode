class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int sum = 0;
        int j = 0;
        string ans="";

        for (int i = 0; i < n; i++) {
            sum += s[i] - '0';

            while (j <= i && sum > k) {
                sum -= s[j] - '0';
                j++;
            }
            while(j<=i && sum==k)
            {
                string curr=s.substr(j,i-j+1);
                if(ans=="" || ans.size()>curr.size() || (curr.size()==ans.size() && curr<ans))
                {
                    ans=curr;
                }
                sum -= s[j] - '0';
                j++;
            }
            
        }

       return ans;
    }
};
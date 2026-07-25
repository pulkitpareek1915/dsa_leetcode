class Solution {
public:
    bool static comp(string &a,string &b)
    {
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            s.push_back(to_string(nums[i]));
            if(nums[i]==0) cnt++;
        }
        if(cnt==n) return "0";
        sort(s.begin(),s.end(),comp);
        string largest;
        for(int i=0;i<n;i++)
        {
            largest+=s[i];
        }
        return largest;
    }
};
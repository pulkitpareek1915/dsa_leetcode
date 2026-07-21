class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int m=s.size();
        int index=0;
        for(int i=m-2;i>=0;i--)
        {
            if(s[i+1]-'0'>s[i]-'0')
            {
                index=i;
                break;
            }
        }
        if (index == -1) return -1;
        for(int i=m-1;i>=index;i--)
        {
            if(s[i]-'0'>s[index]-'0')
            {
                swap(s[i],s[index]);
                break;
            }
        }
         reverse(s.begin() + index + 1, s.end());

        long long ans = stoll(s);
         if (ans > INT_MAX) return -1;
        if(ans>n) return (int)ans;
        return -1;
    }
};
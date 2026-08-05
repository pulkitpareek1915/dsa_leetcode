class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        vector<int> vowel(n,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                vowel[i]=2;
            }
            else if(s[i]=='e')
            {
                vowel[i]=4;
            }
            else if(s[i]=='i')
            {
                vowel[i]=8;
            }
            else if(s[i]=='o')
            {
                vowel[i]=16;
            }
            else if(s[i]=='u')
            {
                vowel[i]=32;
            }
            else{
                continue;
            }
        }
        unordered_map<int ,int> map;
        map[0]=-1;
        int maxlen=0;
        int xor1=0;
        for(int i=0;i<n;i++)
        {
            xor1=xor1^vowel[i];
            if(map.count(xor1))
            {
                maxlen=max(maxlen,i-map[xor1]);
            }
            else{
                map[xor1]=i;
            }
        }
        return maxlen;
    }
};
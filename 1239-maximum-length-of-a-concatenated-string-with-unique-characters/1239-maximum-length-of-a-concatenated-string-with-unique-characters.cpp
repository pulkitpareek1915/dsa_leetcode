class Solution {
public:
    unordered_map<string,int> mpp;
    bool hasduplicate(string temp, string s)
    {
        vector<int> freq(26,0);

        for(char c : temp)
        {
            freq[c-'a']++;
            if(freq[c-'a'] > 1) return true;
        }

        for(char c : s)
        {
            freq[c-'a']++;
            if(freq[c-'a'] > 1) return true;
        }

        return false;
    }
    int solve(int index,vector<string> arr,string temp,int n)
    {
        if(index>=n)
        {
            return temp.size();
        }
        int pick=0;
        int notpick=0;
        if(mpp.find(temp)!=mpp.end())
        {
            return mpp[temp];
        }
        if(hasduplicate(temp,arr[index]))
        {
            notpick=solve(index+1,arr,temp,n);
        }
        else{
            pick=solve(index+1,arr,temp+arr[index],n);
            notpick=solve(index+1,arr,temp,n);
        }
        return mpp[temp]=max(pick,notpick);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        mpp.clear();
        return solve(0,arr,temp,n);
    }
};
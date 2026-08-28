class Solution {
public:
   static int sum1(int x)
    {
        int sum=0;
        while(x!=0)
        {
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }
    static bool comp(int &a,int &b)
    {
        int sa=sum1(a);
        int sb=sum1(b);
        if(sa==sb) return a < b;
        return sa < sb;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> arr=nums;
        int n=nums.size();
        sort(arr.begin(),arr.end(),comp);
        unordered_map<int,int> map;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            map[nums[i]]=i;
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i] || arr[i]==nums[i]) continue;
            int cycle_size=0;
            int j=i;
            while(!vis[j])
            {
                vis[j]=1;
                j=map[arr[j]];
                cycle_size++;
            }
            if(cycle_size>1)
            {
                ans+=(cycle_size-1);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> map;
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            map[arr[i]]++;
        }
        vector<int> ans;
        for(auto it:map)
        {
            ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());
        int cnt=0;
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            sum=sum+ans[i];
            if(sum<=k)
            {
                cnt++;
            }
            else{
                break;
            }
        }
        return ans.size()-cnt;
    }
};
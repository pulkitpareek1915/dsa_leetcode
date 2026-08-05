class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n=arr.size();
        long long cs=0;
        int evencount=1;
        int oddcount=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            cs+=arr[i];
            if(cs%2==0)
            {
                count+=oddcount;
                evencount++;
            }
            else{
                count+=evencount;
                oddcount++;
            }
            count=count%MOD;
        }
        return count;
    }
};
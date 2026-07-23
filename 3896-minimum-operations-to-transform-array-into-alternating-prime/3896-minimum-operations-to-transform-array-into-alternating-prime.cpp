class Solution {
public:
    bool prime(int n){
        if(n<=1) return false;
        if(n==2) return true;
        if(n%2==0) return false;
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            {
                if(i%2==0 && !prime(nums[i])){
                    while(!prime(nums[i])){
                        nums[i]++;
                        ans++;
                    }
                }
                if(i%2==1 && prime(nums[i])){
                    while(prime(nums[i])){
                        nums[i]++;
                        ans++;
                    }
                }
            }
        return ans;
    }
};
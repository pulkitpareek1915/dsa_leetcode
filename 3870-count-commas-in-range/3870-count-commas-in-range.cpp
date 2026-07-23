class Solution {
public:
    int countCommas(int n) {
        int count=0;
        int k=n;
        int ans=0;
        while(k!=0){
            k=k/10;
            count++;
        }
        if(count>=4){
            for(int i=1000;i<=n;i++){
                ans++;
            }
        }
        return ans;
    }
};
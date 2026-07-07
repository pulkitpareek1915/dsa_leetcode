class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=intervals.size();
        if(n==1) return 1;
        int cnt=0;
        int left=intervals[0][1];
      int right=intervals[1][1];
        for(int i=0;i<n-1;i++)
        {
          right=intervals[i+1][1];
            if(right<=left)
            {
                cnt++;
            }
            else{
                left=right;
            }
            cout<<left<<" "<<right<<endl;
        }
        return n-cnt;
    }
};
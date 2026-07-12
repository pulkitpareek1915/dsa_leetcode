class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n=intervals.size();
       if(n==1) return intervals;
       sort(intervals.begin(),intervals.end());

       vector<vector<int>> ans;
       int laststart=intervals[0][0];
       int lastend=intervals[0][1];
       int flag=0;
       for(int i=1;i<n;i++)
       {
            if(intervals[i][0]<=lastend)
            {
                
                lastend=max(intervals[i][1],lastend);
            }
            else{
                ans.push_back({laststart,lastend});
                laststart=intervals[i][0];
                lastend=intervals[i][1];
                
            }
       } 
       ans.push_back({laststart,lastend});
       return ans;
    }
};
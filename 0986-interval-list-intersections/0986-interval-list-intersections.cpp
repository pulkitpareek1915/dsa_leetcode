class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        sort(firstList.begin(),firstList.end());
        sort(secondList.begin(),secondList.end());
        int n=secondList.size();
        int m=firstList.size();
        int i=0;
        int j=0;
        while(i<m && j<n)
        {
            int fs=firstList[i][0];
            int fe=firstList[i][1];
            int ss=secondList[j][0];
            int se=secondList[j][1];
            int start=max(fs,ss);
            int last=min(fe,se);
            if(start<=last) ans.push_back({start,last});
            if(fe<se) i++;
            else j++;
        
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> genrate_row(int row)
    {
        vector<int> ans;
        long long prod=1;
        ans.push_back(1);
        for(int col=1;col<row;col++)
        {
            prod=prod*(row-col);
            prod=prod/col;
            ans.push_back(prod);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> ans;
      for(int i=1;i<=numRows;i++)
      {
        ans.push_back(genrate_row(i));
      }
      return ans;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> ans;
        long long prod=1;
        ans.push_back(1);
        for(int col=1;col<rowIndex;col++)
        {
            prod=prod*(rowIndex-col);
            prod=prod/(col);
            ans.push_back(prod);
        }
        return ans;
    }
};
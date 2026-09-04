class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> degree;
        for(auto it:edges)
        {
            degree[it[0]]++;
            degree[it[1]]++;
        }
        for(auto it:degree)
        {
            int node=it.first;
            int nodedegree=it.second;
            if(nodedegree==edges.size())
            {
                return node;
            }
        }
        return -1;
    }
};
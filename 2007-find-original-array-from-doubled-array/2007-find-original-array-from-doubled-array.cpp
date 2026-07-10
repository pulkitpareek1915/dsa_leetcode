class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset<int> st;
        int n=changed.size();
        sort(changed.begin(),changed.end());
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            st.insert(changed[i]);
        }
        for(int i=0;i<n;i++)
        {
            int lowest=changed[i];
            if(st.find(lowest)!=st.end())
            {
                ans.push_back(lowest);
                st.erase(st.find(lowest));
                if(st.find(2*lowest)!=st.end())
                {
                    st.erase(st.find(2*lowest));
                }
            }
        }
        if(ans.size()!=n/2) return {};
        return ans;
    }
};
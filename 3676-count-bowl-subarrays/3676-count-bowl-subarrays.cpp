class Solution {
public:
    void nextG(vector<int>& nums, vector<int>& nge){
        int n = nums.size();
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(!st.empty()) nge[i] = st.top();
            st.push(i);
        }
    }
    void prevG(vector<int>& nums, vector<int>& pge){
        int n = nums.size();
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(!st.empty()) pge[i] = st.top();
            st.push(i);
        }
    }
    long long bowlSubarrays(vector<int>& nums) {
       int n = nums.size();
       vector<int> nge(n, n);
       vector<int> pge(n, -1);
       nextG(nums, nge);
       prevG(nums, pge);

       int count = 0;

       for(int i=0; i<n; i++){
        if(nge[i] != n && pge[i] != -1) count++;
       }
       return count;
    }
};
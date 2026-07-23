class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> freq;
        int ans=0;
       for( char c: s){
           freq[c]++;
       }
        unordered_set<char> vis;
        for(auto it:freq){
            char c=it.first;
        if(vis.count(c)) 
        {
            continue;
        }
        char mirr;
        if(isalpha(c)){
            mirr='z'-(c-'a');
        }
        else{
            mirr='9'-(c-'0');
        }
        int f1=freq[c];
        int f2=freq.count(mirr) ? freq[mirr]:0;
        ans+=abs(f1-f2);
        vis.insert(c);
        vis.insert(mirr);
    }
    
    return ans;
    }
};
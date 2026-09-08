class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                freq[s[i] - 'a']++;
            }
        }

        priority_queue<
            pair<int, char>,
            vector<pair<int, char>>,
            greater<pair<int, char>>
        > pq;

        for (int i = 0; i < 26; i++) {
            pq.push({freq[i], char(i + 'a')});
        }

        string temp = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                auto it = pq.top();
                pq.pop();

                int cost = it.first;
                char ch = it.second;

                temp += ch;

                pq.push({cost + 1, ch});
            }
        }

        sort(temp.begin(), temp.end());

        int index = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = temp[index];
                index++;
            }
        }

        return s;
    }
};
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        stack<char> st;
        vector<int> lastIndex(26);
        vector<bool> taken(26, false);
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (taken[idx])
                continue;
            while (!st.empty() && s[i] < st.top() && lastIndex[st.top() - 'a'] > i) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            taken[idx] = true;
        }
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
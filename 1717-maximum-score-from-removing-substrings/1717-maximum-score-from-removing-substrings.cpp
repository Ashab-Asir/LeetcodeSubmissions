class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int ans = 0;
        stack<char> st;
        if (y >= x) {
            for (int i = 0; i < n; i++) {
                if (s[i] == 'a' && !st.empty() && st.top() == 'b') {
                    st.pop();
                    ans += y;
                } else {
                    st.push(s[i]);
                }
            }
            string s2;
            while (!st.empty()) {
                s2 += st.top();
                st.pop();
            }
            reverse(s2.begin(),s2.end());
            for (int i = 0; i < s2.size(); i++) {
                if (s2[i] == 'b'&& !st.empty() && st.top() == 'a') {
                    st.pop();
                    ans += x;
                } else {
                    st.push(s2[i]);
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (s[i] == 'a' && !st.empty() && st.top() == 'b' ) {
                    st.pop();
                    ans += x;
                } else {
                    st.push(s[i]);
                }
            }
            string s2;
            while (!st.empty()) {
                s2 += st.top();
                st.pop();
            }
            reverse(s2.begin(),s2.end());
            for (int i = 0; i < st.size(); i++) {
                if (s2[i] == 'b' && st.top() == 'a' && !st.empty()) {
                    st.pop();
                    ans += y;
                } else {
                    st.push(s2[i]);
                }
            }
        }
        return ans;
    }
};
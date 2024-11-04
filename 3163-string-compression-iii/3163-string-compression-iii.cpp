class Solution {
public:
    string compressedString(string word) {
        int cnt = 1;
        string ans = "";
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1]) {
                cnt++;
                if (cnt == 9) {
                    ans += to_string(cnt);
                    ans += word[i - 1];
                    cnt = 0;
                }
            } else {
                if (cnt != 0) {
                    ans += to_string(cnt);
                    ans += word[i - 1];
                }
                cnt = 1;
            }
        }
        ans += to_string(cnt);
        ans += word[word.size() - 1];
        return ans;
    }
};
class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        int n = start.size();
        int m = target.size();
        while (i < start.size() || j < target.size()) {
            while (i < n && start[i] == '_') {
                i++;
            }
            while (j < n && target[j] == '_') {
                j++;
            }
            if (i == n || j == n) {
                return i == n && j == n;
            }
            if (start[i] != target[j]) {
                return false;
            }
            if (start[i] == 'L' && i < j) {
                return false;
            }
            if (start[i] == 'R' && i > j) {
                return false;
            }
            i++;
            j++;
        }

        return true;
    }
};
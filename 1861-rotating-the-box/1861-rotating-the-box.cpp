class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }
        for(vector<char>& row : result) {
            reverse(begin(row), end(row));
        }
        for(int j = 0; j < m; j++) {
            for(int i = n-1; i >= 0; i--) {
                if(result[i][j] == '.') {
                    int stoneRow = -1;
                    for(int k = i-1; k >= 0; k--) {
                        if(result[k][j] == '*') {
                            break;
                        } else if(result[k][j] == '#') {
                            stoneRow = k;
                            break;
                        }
                    }
                    if(stoneRow != -1) {
                        result[i][j] = '#';
                        result[stoneRow][j] = '.';
                    }
                }
            }
        }

        return result;
    }
};

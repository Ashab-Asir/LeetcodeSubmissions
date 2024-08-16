class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int minIdx, maxIdx;
        for (int i = 0; i < arrays.size(); i++) {
            for (int j = 0; j < arrays[i].size(); j++) {
                if (arrays[i][j] > maxi) {
                    maxi = arrays[i][j];
                    maxIdx = i;
                }
            }
        }
        for (int i = 0; i < arrays.size(); i++) {
            if (maxIdx != i) {
                for (int j = 0; j < arrays[i].size(); j++) {
                    if (arrays[i][j] < mini) {
                        mini = arrays[i][j];
                    }
                }
            }
        }
        return maxi - mini;
    }
};
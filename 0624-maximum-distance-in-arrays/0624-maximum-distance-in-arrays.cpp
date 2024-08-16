class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini1 = INT_MAX,mini2=INT_MAX;
        int maxi1 = INT_MIN,maxi2=INT_MIN;
        int minIdx, maxIdx;
        for (int i = 0; i < arrays.size(); i++) {
            for (int j = 0; j < arrays[i].size(); j++) {
                if (arrays[i][j] > maxi1) {
                    maxi1 = arrays[i][j];
                    maxIdx = i;
                }
            }
        }
        for (int i = 0; i < arrays.size(); i++) {
            if (maxIdx != i) {
                for (int j = 0; j < arrays[i].size(); j++) {
                    if (arrays[i][j] < mini1) {
                        mini1 = arrays[i][j];
                    }
                }
            }
        }

        for (int i = 0; i < arrays.size(); i++) {
            for (int j = 0; j < arrays[i].size(); j++) {
                if (arrays[i][j] < mini2) {
                    mini2 = arrays[i][j];
                    minIdx = i;
                }
            }
        }
        for (int i = 0; i < arrays.size(); i++) {
            if (minIdx != i) {
                for (int j = 0; j < arrays[i].size(); j++) {
                    if (arrays[i][j] > maxi2) {
                        maxi2 = arrays[i][j];
                    }
                }
            }
        }
        int diff1=maxi1-mini1;
        int diff2=maxi2-mini2;
        return max(diff1,diff2);
    }
};
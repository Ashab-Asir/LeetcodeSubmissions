class Solution {
public:
    int lowerBound(int minPotions, vector<int> potions) {
        int ind = -1;
        int low = 0, high = potions.size()-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (potions[mid] >= minPotions) {
                ind = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ind;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        vector<int> vec;
        for (int i = 0; i < spells.size(); i++) {
            long long minPotions = ceil(1.0 * success / spells[i]);
            int index = lowerBound(minPotions, potions);
            if (minPotions>potions[potions.size()-1]) {
                vec.push_back(0);
            } else {
                long long ans = potions.size() - index;
                vec.push_back(ans);
            }
        }
        return vec;;
    }
};
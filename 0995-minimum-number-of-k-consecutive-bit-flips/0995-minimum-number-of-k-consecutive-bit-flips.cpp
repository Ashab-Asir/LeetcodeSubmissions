class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> isFliped(n, false);
        int flipCnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k && isFliped[i - k] == true) {
                flipCnt--;
            }
            if (flipCnt % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                isFliped[i] = true;
                ans++;
                flipCnt++;
            }
        }
        return ans;
    }
};
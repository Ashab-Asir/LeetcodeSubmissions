class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, right = 0, maxLength = 0;

        while (right < nums.size()) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                left++;
                if (left > maxDeque.front()) {
                    maxDeque.pop_front();
                }
                if (left > minDeque.front()) {
                    minDeque.pop_front();
                }
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        deque<int>v;
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            v.pop_front();
            auto low=lower_bound(v.begin(),v.end(),lower-nums[i]);
            auto high=upper_bound(v.begin(),v.end(),upper-nums[i]);
            ans+=(high-low);
        }
        return ans;
    }
};
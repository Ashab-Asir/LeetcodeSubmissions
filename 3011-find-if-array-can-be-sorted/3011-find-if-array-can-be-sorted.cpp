class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            int setCnt1=__builtin_popcount(nums[i]);
            for(int j=i+1;j<nums.size();j++){
                int setCnt2=__builtin_popcount(nums[j]);
                if(nums[i]>nums[j] && setCnt1!=setCnt2){
                    return false;
                }
            }
        }
        return true;
    }
};
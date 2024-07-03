class Solution {
public:
    int minDifference(vector<int>& nums) {
        int result=INT_MAX,n=nums.size();
        if(n<=4){
            return 0; 
        }
        sort(nums.begin(),nums.end());
        result=min(result,nums[n-4]-nums[0]);
        result=min(result,nums[n-1]-nums[3]);
        result=min(result,nums[n-3]-nums[1]);
        result=min(result,nums[n-2]-nums[2]);
        return result;
    }
};
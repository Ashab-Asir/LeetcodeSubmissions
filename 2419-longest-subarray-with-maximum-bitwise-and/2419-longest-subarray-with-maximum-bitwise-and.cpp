class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=maxVal){
                maxVal=nums[i];
            }
        }
        int streak=0;
        int result=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxVal){
                streak++;
            }
            else{
                result=max(result,streak);
                streak=0;
            }
        }
        return max(result,streak);
    }
};
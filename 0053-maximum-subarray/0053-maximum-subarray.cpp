class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                maxi=max(sum,maxi);
                sum=0;
            }
            else{
                maxi=max(sum,maxi);
            }
        }
        return maxi;
    }
};
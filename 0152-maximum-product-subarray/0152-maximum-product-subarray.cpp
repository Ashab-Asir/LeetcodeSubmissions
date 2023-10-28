class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi=INT_MIN;
        long long suff=1,pre=1;
        for(int i=0;i<nums.size();i++){
            suff*=nums[i];
            pre*=nums[nums.size()-i-1];
            maxi=max(maxi,max(suff,pre));
            if(nums[i]==0){
                suff=1;
            }
            if(nums[nums.size()-i-1]==0){
                pre=1;
            }
        }
        return maxi;
    }
};
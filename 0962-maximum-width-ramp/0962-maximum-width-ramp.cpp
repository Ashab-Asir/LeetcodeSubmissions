class Solution {
public:
    int maxi=0;
    int maxWidthRamp(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=nums.size()-1;j>=0 && j>i;j--){
                if(j-i<=maxi){
                    break;
                }
                if(nums[i]<=nums[j]){
                    maxi=max(maxi,j-i);
                    break;
                }
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int result(vector<int>nums,long long mid){
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=ceil(nums[i]/(mid*1.0));
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int ans;
        int high=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>high){
                high=nums[i];
            }
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(result(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
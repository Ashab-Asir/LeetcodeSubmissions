class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int ans=nums.size();
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

      int upperBound(vector<int>& nums, int target){
        int ans=nums.size();
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lowerBound(nums,target);
        int second=upperBound(nums,target);
        if(first==nums.size() || nums[first]!=target){
            return {-1,-1};
        }
        else{
            return {first,second-1};
        }
    }
};
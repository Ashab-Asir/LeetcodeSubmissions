class Solution {
public:
    int cntInt(vector<int>nums,int mid){
        int cnt=1,take=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+take<=mid){
                take+=nums[i];
            }
            else{
                cnt++;
                take=nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            sum+=nums[i];
        }
        int low=maxi,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int numberOfInteger=cntInt(nums,mid);
            if(numberOfInteger>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
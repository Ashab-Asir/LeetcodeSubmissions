class Solution {
public:
    int cntPair(vector<int>&nums,int mid){
        int n=nums.size();
        int i=0;
        int j=1;
        int cnt=0;
        while(j<n){
            while(nums[j]-nums[i]>mid){
                i++;
            }
            cnt+=(j-i);
            j++;
        } 
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[n-1]-nums[0];
        int result=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            int cnt=cntPair(nums,mid);
            if(cnt<k){
                left=mid+1;
            }
            else{
                result=mid;
                right=mid-1;
            }
        }
        return result;
    }
};
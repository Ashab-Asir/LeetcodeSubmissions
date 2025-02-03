class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1,inc_max=1,dec_max=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
            }
            else{
                inc_max=max(inc,inc_max);
                inc=1;
            }
            if(nums[i]<nums[i-1]){
                dec++;
            }
            else{
                dec_max=max(dec_max,dec);
                dec=1;
            }
        }
        inc_max=max(inc,inc_max);
        dec_max=max(dec,dec_max);
        return max(dec_max,inc_max);
    }
};
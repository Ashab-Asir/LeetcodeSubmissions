class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++){
            if(i+1<n){
                if(nums[i]<nums[i+1]){
                    continue;
                }
                else{
                    cnt++;
                }
            }
        }
        if(nums[0]<nums[n-1]){
            cnt++;
        }
        return cnt<=1;
    }
};
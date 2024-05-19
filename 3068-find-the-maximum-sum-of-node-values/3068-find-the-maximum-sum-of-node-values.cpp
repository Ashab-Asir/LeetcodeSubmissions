class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        long long sum=0,cnt=0;
        int minDecrease=INT_MAX;
        for(int i=0;i<n;i++){
            if((nums[i]^k)>nums[i]){
                sum+=(nums[i]^k);
                cnt++;
            }
            else{
                sum+=nums[i];
            }
            minDecrease=min(minDecrease,abs(nums[i]-(nums[i]^k)));
        }
        
        if(cnt%2==0){
            return sum;
        }
        return sum-minDecrease;
    }
};
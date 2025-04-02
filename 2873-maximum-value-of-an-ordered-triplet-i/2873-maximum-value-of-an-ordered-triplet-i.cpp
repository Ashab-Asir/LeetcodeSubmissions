class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0;
        for(long long i=0;i<nums.size();i++){
            for(long long j=i+1;j<nums.size();j++){
                for(long long k=j+1;k<nums.size();k++){
                    long long sum=(nums[i]-nums[j]);
                    sum*=nums[k];
                    maxi=max(maxi,sum);
                }
            }
        }
        return maxi;
    }
};
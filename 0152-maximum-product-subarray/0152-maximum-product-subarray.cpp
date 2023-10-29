class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long preFix=1,sufFix=1,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            preFix*=nums[i];
            sufFix*=nums[nums.size()-1-i];
            maxi=max(maxi,max(preFix,sufFix));
            if(preFix==0){
                preFix=1;
            }
            if(sufFix==0){
                sufFix=1;
            }
        }
        return maxi;
    }
};
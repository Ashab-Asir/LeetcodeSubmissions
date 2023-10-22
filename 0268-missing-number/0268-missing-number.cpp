class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans;
        vector<int>hash(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]==0){
                ans=i;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            x=x|nums[i];
        }
        return x<<(n-1);
    }
};
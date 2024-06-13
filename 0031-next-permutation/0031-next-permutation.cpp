class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            sort(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1;i>=index+1;i--){
                if(nums[index]<nums[i]){
                    swap(nums[index],nums[i]);
                    break;
                }
            }
            sort(nums.begin()+index+1,nums.end());
        }
    }
};
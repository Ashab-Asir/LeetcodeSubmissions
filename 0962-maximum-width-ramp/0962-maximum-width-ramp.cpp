class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n,0);
        temp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            temp[i]=max(temp[i+1],nums[i]);
        }
        int i=0,j=0;
        int ans=0;
        while(j<n){
            while(i<j && nums[i]>temp[j]){
                i++;
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};
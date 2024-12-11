class Solution {
    bool f(vector<int> &nums, int k, int len)
    {
        int n=nums.size();
        for(int i=0; i<=(n-len); i++)
        {
            if(nums[i]+k>=nums[i+len-1]-k)
                return true;
        }
        return false;
    }
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int n=nums.size();
        sort(nums.begin(), nums.end());  
        int low=1, high=n, ans=1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(f(nums, k, mid))
            {
                ans=mid; 
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(!ans.empty() && nums[i][1]<=ans.back()[1]){
                continue;
            }
            int start=nums[i][0],end=nums[i][1];
            for(int j=i+1;j<nums.size();j++){
                if(nums[j][0]<=end){
                    end=max(end,nums[j][1]);
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};
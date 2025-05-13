class Solution {
public:
    void find(vector<int>&nums,vector<int>&ds,vector<int>&mp,vector<vector<int>>&ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!mp[i]){
                ds.push_back(nums[i]);
                mp[i]=1;
                find(nums,ds,mp,ans);
                ds.pop_back();
                mp[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>mp;
        for(int i=0;i<nums.size();i++){
            mp.push_back(0);
        }
        find(nums,ds,mp,ans);
        return ans;
    }
};
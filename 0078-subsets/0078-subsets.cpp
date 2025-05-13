class Solution {
public:
    void generate(vector<vector<int>>&ans,vector<int>temp,vector<int>nums,int index){
        if(index==nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[index]);
        generate(ans,temp,nums,index+1);
        temp.pop_back();
        generate(ans,temp,nums,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        generate(ans,temp,nums,0);
        return ans;
    }
};
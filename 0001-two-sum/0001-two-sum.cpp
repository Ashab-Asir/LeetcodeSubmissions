class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int,int>mp;
      for(int i=0;i<nums.size();i++){
          if(mp.find(target-nums[i])==mp.end()){
              mp[nums[i]]=i;
          }
          else{
              vector<int>ans;
              ans.push_back(mp[target-nums[i]]);
              ans.push_back(i);
              return ans;
          }
      }
      vector<int>vec(-1,-1);
      return vec;
    }
};
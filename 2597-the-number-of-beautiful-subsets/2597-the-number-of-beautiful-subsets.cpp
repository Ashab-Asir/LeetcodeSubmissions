class Solution {
public:
    void solve(int ind,vector<int>&nums,int k,int &cnt,map<int,int>&mp){
        if(ind==nums.size()){
            cnt++;
            return ;
        }
        //not take
        solve(ind+1,nums,k,cnt,mp);
        //take
        if(!mp[nums[ind]-k] && !mp[nums[ind]+k]){
            mp[nums[ind]]++;
            solve(ind+1,nums,k,cnt,mp);
            mp[nums[ind]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int cnt=0;
        map<int,int>mp;
        solve(0,nums,k,cnt,mp);
        return cnt-1;
    }
};
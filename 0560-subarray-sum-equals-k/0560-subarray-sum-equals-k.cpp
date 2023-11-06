class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       map<int,int>mp;
       mp[0]=1;
       int cnt=0;
       long long prefixSum=0;
       for(int i=0;i<nums.size();i++){
           prefixSum+=nums[i];
           int rem=prefixSum-k;
           if(mp.find(rem)!=mp.end()){
               cnt+=mp[rem];
           }
           mp[prefixSum]++;
       }
       return cnt;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int prefixSum=0;
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            int x=prefixSum-k;
            if(mp.find(x)!=mp.end()){
                cnt+=(mp[x]);
            }
            mp[prefixSum]++;
        }
        return cnt;
    }
};
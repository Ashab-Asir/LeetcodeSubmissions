class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        long long cnt=0;
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;
            while(abs(mp.rbegin()->first - mp.begin()->first)>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans=0,maxi=INT_MIN;
        for(auto it:mp){
            if(it.second>maxi){
                maxi=max(it.second,maxi);
                ans=it.second;
            }
            else if(it.second==maxi){
                ans+=it.second;
            }
        }
        return ans;
    }
};
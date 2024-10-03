class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> lastPos;
        lastPos[0]=-1;
        long long ps=0,s=0;
        for (int i=0;i<nums.size();i++) s+=nums[i];
        
        int m=s%p,ans=nums.size();
        if (m==0) return 0;
        for (int i=0;i<nums.size();i++){
            ps+=nums[i];
            if (ps-m>=0 && lastPos.find((ps-m)%p)!=lastPos.end()){
                ans = min(ans,i-lastPos[(ps-m)%p]);
            }
            lastPos[ps%p]=i;
        }
              
        return (ans==nums.size()?-1:ans);
    }
};
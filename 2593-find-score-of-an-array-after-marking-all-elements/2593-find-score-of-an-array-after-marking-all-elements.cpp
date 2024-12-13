class Solution {
public:
    long long findScore(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
           mp[nums[i]].push_back(i);
        }
        long long score=0;
        for(auto it:mp){
            int num=it.first;
            vector list=it.second;
            for(int i=0;i<list.size();i++){
                int idx=list[i];
                if(nums[idx]!=-1){
                    score+=nums[idx];
                    nums[idx]=-1;
                    if(idx+1<nums.size()){
                        nums[idx+1]=-1;
                    }
                    if(idx-1>=0){
                        nums[idx-1]=-1;
                    }
                }
            }
        }
        return score;
    }
};
class Solution {
public:
    void find(int idx,int target,vector<int>& candidates,vector<int>&ds,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return ;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1])continue;
            if(target<candidates[i])break;
            ds.push_back(candidates[i]);
            find(i+1,target-candidates[i],candidates,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        find(0,target,candidates,ds,ans);
        return ans;
    }
};
class Solution {
public:
    int solve(int ind,vector<int>&nums,int currOr,int maxi){
        if(ind==nums.size()){
            if(currOr==maxi){
               return 1;
            }
            return 0;
        }
        //take
       int take= solve(ind+1,nums,currOr|nums[ind],maxi);
        //not take
       int notTake=solve(ind+1,nums,currOr,maxi);
        return take+notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int x=0;
            for(int j=i;j<nums.size();j++){
                x=x | nums[j];
                if(maxi<x){
                    maxi=x;
                }
            }
        }
       int currOr=0;
       int cnt=0;
       return solve(0,nums,currOr,maxi);
    }
};
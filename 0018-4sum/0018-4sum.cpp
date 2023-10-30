class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        set<vector<int>>st2;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                set<long long>st1;
                for(int k=j+1;k<nums.size();k++){
                    long long total=nums[i];
                    total+=nums[j];
                    total+=nums[k];
                    long long x=target-total;
                    if(st1.find(x)!=st1.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],(int)x};
                        sort(temp.begin(),temp.end());
                        st2.insert(temp);
                    }
                    st1.insert(nums[k]);
                }
            }
        }
        ans={st2.begin(),st2.end()};
        return ans;
    }
};
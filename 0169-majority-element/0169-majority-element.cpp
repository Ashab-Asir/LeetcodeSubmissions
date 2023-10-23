class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int cnt=0,elm;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                elm=nums[i];
                cnt++;
            }
            else if(nums[i]==elm){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return elm; 
    }
};
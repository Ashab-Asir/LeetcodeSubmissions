class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
       int cnt=0,secondLargest=INT_MIN,longest=1;
       for(int i=0;i<nums.size();i++){
           if(nums[i]-1==secondLargest){
               cnt++;
               secondLargest=nums[i];
           }
           else if(nums[i]!=secondLargest){
               cnt=1;
               secondLargest=nums[i];
           }
           longest=max(cnt,longest);
       } 
       return longest;
    }
};
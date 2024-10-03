class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<p){
            return -1;
        }
        if(sum%p==0){
            return 0;
        }
        int len=INT_MAX;
        long long subArraySum=nums[0];
        int i=0,j=0;
        int k=sum%p;
        while(i<nums.size()){
            while(j<i && subArraySum>k){
                subArraySum-=nums[j];
                j++;
            }
            if(subArraySum==k){
                len=min(len,i-j+1);
            }
            i++;
            if(i<nums.size()){
                subArraySum+=nums[i];
            }
        }
        return len==INT_MAX?-1:len;
    }
};
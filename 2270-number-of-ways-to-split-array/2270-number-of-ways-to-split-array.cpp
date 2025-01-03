class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>prefixSum;
        int n=nums.size();
        long long sum=nums[0];
        prefixSum.push_back(sum);
        for(int i=1;i<n;i++){
            sum+=nums[i];
            prefixSum.push_back(sum);
        }
        vector<long long>postfixSum(n,0);
        sum=nums[n-1];
        postfixSum[n-1]=sum;
        for(int i=n-2;i>=0;i--){
            sum+=nums[i];
            postfixSum[i]=sum;
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(prefixSum[i]>=postfixSum[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};
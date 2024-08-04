class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                }
                temp.push_back(sum);
            }
        }
        long long ans=0;
        sort(temp.begin(),temp.end());
        for(int i=left-1;i<right;i++){
            ans+=temp[i];
        }
        long long mod=1e9+7;
        return ans%mod;
    }
};
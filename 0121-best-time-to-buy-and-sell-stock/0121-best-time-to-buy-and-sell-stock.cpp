class Solution {
public:
    int maxProfit(vector<int>& arr) {
       int mini=arr[0],maxi=INT_MIN;
       for(int i=1;i<arr.size();i++){
           int profit=arr[i]-mini;
           maxi=max(maxi,profit);
           mini=min(mini,arr[i]);
       }
       return maxi<=0?0:maxi;
    }
};
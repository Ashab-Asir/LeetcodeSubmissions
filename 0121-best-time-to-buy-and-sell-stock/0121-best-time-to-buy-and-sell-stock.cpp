class Solution {
public:
    int maxProfit(vector<int>& arr) {
       int buy=arr[0],maxProfit=0;
       for(int i=1;i<arr.size();i++){
           int profit=arr[i]-buy;
            maxProfit=max(profit,maxProfit);
            buy=min(arr[i],buy);
       }
       return maxProfit;
    }
};
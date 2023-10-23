class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int buy=arr[0],profit=0;
        for(int i=1;i<arr.size();i++){
            int cost=arr[i]-buy;
            profit=max(profit,cost);
            buy=min(buy,arr[i]);
        }
        return profit;
    }
};
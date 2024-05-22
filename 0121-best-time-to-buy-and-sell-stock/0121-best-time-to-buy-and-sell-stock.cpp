class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
            maxProfit=max(maxProfit,(prices[i]-buy));
            buy=min(buy,prices[i]);
        }
        return maxProfit;
    }
};
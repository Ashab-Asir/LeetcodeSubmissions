class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0;
        int ans = 0;
        ans += numBottles;
        empty = numBottles;
        numBottles = 0;
        while (empty >= numExchange) {
            numBottles = empty / numExchange;
            empty = empty % numExchange;
            empty+=numBottles;
            ans += numBottles;
        }
        return ans;
    }
};
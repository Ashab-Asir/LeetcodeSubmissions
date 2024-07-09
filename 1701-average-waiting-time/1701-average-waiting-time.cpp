class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalTime = 0;
        long long currentTime = customers[0][0];

        int i = 0;
        while (i < customers.size()) {
            int arrival = customers[i][0];
            int cookTime = customers[i][1];
            if (currentTime < arrival) {
                currentTime = arrival;
            }
            totalTime += (currentTime + cookTime) - arrival;
            currentTime = (currentTime + cookTime);
            i++;
        }
        return 1.0 * totalTime / customers.size();
    }
};
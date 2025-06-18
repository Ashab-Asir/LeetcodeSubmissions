class Solution {
public:
    // time/space: O(nlogn)/O(logn)
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // sort the array
        sort(nums.begin(), nums.end());

        // check the condition
        for (int i = 0; i < nums.size(); i += 3) {
            if ((nums[i + 2] - nums[i]) > k) return vector<vector<int>>();
        }

        // divide the array into arrays of size `3`
        vector<vector<int>> arrays;
        for(int i = 0; i < nums.size(); i += 3){
            vector<int>subArr;
            for(int j=i;j<=(i+2);j++){
                subArr.push_back(nums[j]);
            }
            arrays.push_back(subArr);
        }
        return arrays;
    }
};
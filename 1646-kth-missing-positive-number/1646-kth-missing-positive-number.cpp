class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>ans;
        for(int i=1;i<=10001;i++){
            int exist=0;
            for(int j=0;j<arr.size();j++){
                if(arr[j]==i){
                    exist=1;
                    break;
                }
            }
            if(exist==0){
                ans.push_back(i);
            }
        }
        return ans[k-1];
    }
};
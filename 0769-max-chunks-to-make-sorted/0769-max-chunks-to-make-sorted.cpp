class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int prefixSum=0,indexSum=0;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            indexSum+=i;
            if(prefixSum==indexSum){
                cnt++;
            }
        }
        return cnt;
    }
};
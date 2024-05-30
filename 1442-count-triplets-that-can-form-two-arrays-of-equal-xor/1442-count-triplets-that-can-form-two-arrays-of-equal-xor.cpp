class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int Xor = arr[i];
            for (int j = i + 1; j < n; j++) {
                Xor = Xor ^ arr[j];
                if (Xor == 0) {
                    cnt += (j - i);
                }
            }
        }
        return cnt;
    }
};
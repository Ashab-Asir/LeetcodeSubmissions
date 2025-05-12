class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    for (int k = 0; k < n; k++) {
                        if (k != j && k != i && digits[i]!=0) {
                            int num =
                                digits[k] + digits[j] * 10 + digits[i] * 100;
                            if (num % 2 == 0) {
                                st.insert(num);
                            }
                        }
                    }
                }
            }
        }
        vector<int>ans;
        for (auto it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};
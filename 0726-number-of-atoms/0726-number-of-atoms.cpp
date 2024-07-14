class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;
                string mul;
                while (i < n && isdigit(formula[i])) {
                    mul.push_back(formula[i]);
                    i++;
                }
                if (!mul.empty()) {
                    int mulInteger = stoi(mul);
                    for (auto it : curr) {
                        string element = it.first;
                        int count = it.second;
                        curr[element] = count * mulInteger;
                    }
                }

                for (auto it : curr) {
                    string element = it.first;
                    int count = it.second;
                    st.top()[element] += count;
                }
            } else {
                string currElement;
                currElement.push_back(formula[i]);
                i++;
                while (i < n && islower(formula[i])) {
                    currElement.push_back(formula[i]);
                    i++;
                }
                string currCnt;

                while (i < n && isdigit(formula[i])) {
                    currCnt.push_back(formula[i]);
                    i++;
                }

                int currNum = !currCnt.empty() ? stoi(currCnt) : 1;
                st.top()[currElement] += currNum;
            }
        }
        map<string, int> sortmp(begin(st.top()), end(st.top()));
        string ans;
        for (auto it : sortmp) {
            string ele = it.first;
            int cnt = it.second;
            ans += ele;
            if (cnt > 1) {
                ans += to_string(cnt);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int dp[1002][1002][3];

    int count(int p, int i, int size, vector<int>& r) {
        int cnt = 0; 
        if (size == 3) return 1; 
        if (i == r.size()) return 0;
        
        if (this->dp[p + 1][i][size] != -1) return this->dp[p + 1][i][size];
       
        cnt += count(p, i + 1, size, r);
        if (p == -1 || r[i] < r[p]) cnt += count(i, i + 1, size + 1, r);

        return this->dp[p + 1][i][size] = cnt;
    }

    int numTeams(vector<int>& rating) {
        memset(this->dp, -1, sizeof(this->dp));
        int cnt = count(-1, 0, 0, rating);
        memset(this->dp, -1, sizeof(this->dp)); 
        reverse(rating.begin(), rating.end());
        return cnt + count(-1, 0, 0, rating);
    }
};
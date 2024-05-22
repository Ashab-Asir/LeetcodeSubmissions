class Solution {
public:
    vector<int>genarateRow(int row){
        vector<int>temp;
        int ans=1;
        temp.push_back(ans);
        for(int col=1;col<row;col++){
            ans*=(row-col);
            ans/=col;
            temp.push_back(ans);
        }
        return temp;
    }
    void solve(int numRow,vector<vector<int>>&ans){
        for(int i=1;i<=numRow;i++){
            ans.push_back(genarateRow(i));
        }
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        solve(numRows,ans);
        return ans;
    }
};
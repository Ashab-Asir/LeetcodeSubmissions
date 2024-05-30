class Solution {
public:
    vector<int>genarateRow(int row){
        vector<int>rowVector;
        int num=1;
        rowVector.push_back(num);
        for(int i=1;i<row;i++){
            num*=(row-i);
            num=(num/i);
            rowVector.push_back(num);
        }
        return rowVector;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(genarateRow(i));
        }
        return ans;
    }
};
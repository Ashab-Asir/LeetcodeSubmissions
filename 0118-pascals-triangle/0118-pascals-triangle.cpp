class Solution {
public:
 vector<int>printRow(int rowIndex){
            vector<int>row;
            long long ans=1;
            row.push_back(ans);
            for(int i=1;i<rowIndex;i++){
                ans=ans*(rowIndex-i);
                ans=ans/i;
                row.push_back(ans);
            }
            return row;
        }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>temp=printRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};
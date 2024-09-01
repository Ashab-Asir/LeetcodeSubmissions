class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n,0));
        if(n*m!=original.size()){
            return {};
        }
        int ind=0;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                ans[i][j]=original[ind];
                ind++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int largest=INT_MIN;
        vector<int>ans;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]>largest){
                    largest=mat[i][j];
                    ans={i,j};
                }
            }
        }
        return ans;
    }
};
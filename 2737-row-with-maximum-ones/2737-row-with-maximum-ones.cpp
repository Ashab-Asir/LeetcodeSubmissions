class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi=INT_MIN,ans;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            if(cnt>maxi){
                maxi=cnt;
                ans=i;
            }
        }
        return {ans,maxi};
    }
};
class Solution {
public:
    void solve(int startRow,int startCol,int side,vector<vector<int>>& matrix,int &cnt){
        int flag=0;
        if(startRow+side<=matrix.size() && startCol+side<=matrix[0].size()){
            
            for(int i=startRow;i<startRow+side;i++){
                for(int j=startCol;j<startCol+side;j++){
                    if(matrix[i][j]!=1){
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    break;
                }
            }
            if(flag==0){
                cnt++;
            }
        }
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=max(n,m);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int side=1;side<=maxi;side++){
                    solve(i,j,side,matrix,cnt);
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    void flipRow(int row,int numberOfCol,vector<vector<int>>& grid){
        for(int j=0;j<numberOfCol;j++){
            if(grid[row][j]==0){
                grid[row][j]=1;
            }
            else{
                grid[row][j]=0;
            }
        }
    }
    int cnt(int col,vector<vector<int>>& grid,int n){
        int x=0;
        for(int i=0;i<n;i++){
            if(grid[i][col]==0){
                x++;
            }
        }
        return x;
    }
    void flipCol(int col,vector<vector<int>>& grid,int n){
        for(int i=0;i<n;i++){
            if(grid[i][col]==0){
                grid[i][col]=1;
            }
            else{
                grid[i][col]=0;
            }
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                flipRow(i,m,grid);
            }
        }
        for(int j=1;j<m;j++){
            int cntZero=cnt(j,grid,n);
            int cntOne=n-cntZero;
            if(cntZero>=cntOne){
                flipCol(j,grid,n);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=(pow(2,m-j-1)*grid[i][j]);
            }
        }
        return sum;
    }
};
class Solution {
public:
    int isMagic(int r, int c, vector<vector<int>>& grid) {
        int sum=0;
        set<int>st;
        for (int i = r; i <= r + 2; i++) {
            for (int j = c; j <= c+2; j++) {
                sum+=grid[i][j];
                if(grid[i][j]<=9){
                    st.insert(grid[i][j]);
                }
                
            }
        }
        if(st.size()!=9){
            return 0;
        }
        for(int i=r;i<=r+2;i++){
            if(grid[i][c]+grid[i][c+1]+grid[i][c+2]!=15){
                return 0;
            }
        }
        for(int i=c;i<=c+2;i++){
            if(grid[r][i]+grid[r+1][i]+grid[r+2][i]!=15){
                return 0;
            }
        }
        if((grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2])!=15 || (grid[r][c+2]+grid[r+1][r+1]+grid[r+2][c])!=15){
            return 0;
        }
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        int ans = 0;
        for (int r = 0; r < rowLen - 2; r++) {
            for (int c = 0; c < colLen - 2; c++) {
                if(isMagic(r,c,grid)==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
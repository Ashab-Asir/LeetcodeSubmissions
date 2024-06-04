class Solution {
public:
    int solve(int i,int j){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        int up=solve(i-1,j);
        int left=solve(i,j-1);
        return up+left;
    }
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};
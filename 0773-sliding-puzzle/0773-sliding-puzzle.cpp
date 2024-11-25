class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int n=2;
        int m=3;
        set< vector<vector<int>> >st;
        st.insert(board);
        vector<vector<int>>ans={{1,2,3},
                                 {4,5,0}};
        queue<pair<int,vector<vector<int>> >>q;
        q.push({0,board});
        while(!q.empty()){
         auto it=q.front();
         q.pop();
         int step=it.first;
         vector<vector<int>>vec=it.second;

         if(vec==ans) return step;
         int r,c; 
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(vec[i][j]==0) {
                  r=i;
                  c=j;
                 }
             }
         } 
         int dr[]={-1,1,0,0};
         int dc[]={0,0,-1,1};
         for(int i=0;i<4;i++){
             vector<vector<int>>temp=vec; 
             int nr=r+dr[i];
             int nc=c+dc[i];
    if(nr>=0 && nr<n && nc>=0 && nc<m){
        swap(temp[r][c],temp[nr][nc]);
        if(st.find(temp)==st.end()){
            st.insert(temp);
             q.push({step+1,temp});
        }  
      }         
         }

        }   
    return -1;
    }
};
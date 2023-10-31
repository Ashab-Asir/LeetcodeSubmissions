class Solution {
public:
    int getNum(int row,int col){
        int res=1;
        for(int i=0;i<=col;i++){
            res=res*(row-i);
            res=res/(i+1);
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        ans.push_back(1);
        long long res=1;
        for(int i=1;i<rowIndex+1;i++){
            res=res*(rowIndex+1-i);
            res=res/i;
            ans.push_back(res);
        }
        return ans;
    }
};
class Solution {
public:
    bool isInvert(vector<int>vec1,vector<int>vec2){
        for(int i=0;i<vec1.size();i++){
            if(vec1[i]==vec2[i]){
                return false;
            }
        }
        return true;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=1;
        for(int i=0;i<n;i++){
            int cnt=1;
            vector<int>vec1;
            vec1=matrix[i];
            for(int j=0;j<n;j++){
                vector<int>vec2;
                if(i!=j){
                    vec2=matrix[j];
                }
                else{
                    continue;
                }
                if(vec1==vec2 || isInvert(vec1,vec2)){
                    cnt++;
                }
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};
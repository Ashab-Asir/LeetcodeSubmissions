class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected,temp;
        temp=heights;
        int cnt=0;
        sort(temp.begin(),temp.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=temp[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
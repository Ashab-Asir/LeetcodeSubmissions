class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int>vec(values.size(),0);
        vec[0]=values[0];
        for(int i=1;i<values.size();i++){
            vec[i]=max(vec[i-1],values[i]+i);
        }
        int maxi=INT_MIN;
        for(int j=1;j<values.size();j++){
            maxi=max(values[j]-j+vec[j-1],maxi);
        }
        return maxi;
    }
};
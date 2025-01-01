class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int left=0;
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                left++;
            }
            int right=0;
            for(int j=i+1;j<n;j++){
                if(s[j]=='1'){
                    right++;
                }
            }
            maxi=max(maxi,left+right);
        }
        return maxi;
    }
};
class Solution {
public:
    int minSwaps(string s) {
        int closing =0;
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                closing++;
            }
            else{
                maxi=max(closing,maxi);
                closing--;
            }
        }
        return (maxi+1)/2;
    }
};
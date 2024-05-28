class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>temp;
        for(int i=0;i<s.size();i++){
            temp.push_back(abs(s[i]-t[i]));
        }
        int maxLength=0;
        int sum=temp[0];
        int n=temp.size();
        int i=0,j=0;
        while(j<n){
            while(i<=j && sum>maxCost){
                sum-=temp[i];
                i++;
            }
            if(sum<=maxCost){
                maxLength=max(maxLength,j-i+1);
            }
            j++;
            if(j<n){
                sum+=temp[j];
            }
        }
        return maxLength;
    }
};
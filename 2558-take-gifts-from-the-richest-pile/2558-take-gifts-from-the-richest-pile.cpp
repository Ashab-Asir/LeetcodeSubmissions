class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        while(k--){
            sort(gifts.begin(),gifts.end());
            gifts[n-1]=sqrt(gifts[n-1]);
        }
        long long ans=0;
        for(int i=0;i<gifts.size();i++){
            ans+=gifts[i];
        }
        return ans;
    }
};
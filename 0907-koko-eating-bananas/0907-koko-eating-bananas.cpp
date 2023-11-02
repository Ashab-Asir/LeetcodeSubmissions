class Solution {
public:
    long long hourToEatBanana(int mid,vector<int>& piles){
        long long totalHour=0;
        for(int i=0;i<piles.size();i++){
           totalHour+=ceil(piles[i]/(mid*1.0));
        }
        return totalHour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        long long ans=INT_MAX;
        int low=1,high=maxi;
        while(low<=high){
            long long mid=(low+high)/2;
            if(hourToEatBanana(mid,piles)<=h){
                ans=min(mid,ans);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
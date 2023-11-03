class Solution {
public:
    int bouquets(vector<int>bloomDay,int mid,int k){
        int bouqetsCnt=0;
        for(int i=0;i<bloomDay.size();i++){
            bloomDay[i]=bloomDay[i]-mid;
        }
        int cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=0){
                cnt++;
                if(cnt==k){
               bouqetsCnt+=1;
               cnt=0;
            }
            }
            else{
                cnt=0;
            }
        }
        return bouqetsCnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi=max(bloomDay[i],maxi);
        }
        int low=1,high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(bouquets(bloomDay,mid,k)>=m){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int makeBouquets(int mid,vector<int>bloomDay,int k){
        int bouquetsCnt=0;
        for(int i=0;i<bloomDay.size();i++){
            bloomDay[i]=bloomDay[i]-mid;
        }
        int cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=0){
                cnt++;
                if(cnt==k){
                    bouquetsCnt++;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return bouquetsCnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1,low=0,high=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            high=max(high,bloomDay[i]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(makeBouquets(mid,bloomDay,k)>=m){
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
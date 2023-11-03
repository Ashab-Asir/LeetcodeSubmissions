class Solution {
public:
    int totalDay(vector<int>weights,int mid){
        int cntDay=1,ship=0;
        for(int i=0;i<weights.size();i++){
           if(weights[i]+ship>mid){
               cntDay+=1;
               ship=weights[i];
           }
           else{
               ship+=weights[i];
           }
        }
        return cntDay;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        for(int i=0;i<weights.size();i++){
            low=max(weights[i],low);
        }
        int high=0;
        int ans;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(totalDay(weights,mid)<=days){
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
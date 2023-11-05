class Solution {
public:
    int ispossible(vector<int>arr,int capacity){
        int cntDay=1,load=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+load<=capacity){
                load+=arr[i];
            }
            else{
                cntDay++;
                load=arr[i];
            }
        }
        return  cntDay;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN,high=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>low){
                low=weights[i];
            }
            high+=weights[i];
        }
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(weights,mid)<=days){
                ans=mid;
                high=mid-1;
            }
            else if(ispossible(weights,mid)>days){
                low=mid+1;
            }
        }
        return ans;
    }
};
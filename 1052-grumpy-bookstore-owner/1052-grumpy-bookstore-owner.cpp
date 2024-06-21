class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int maxUnsatCus=0;
        int currUnSatCus=0;
        for(int i=0;i<minutes;i++){
            currUnSatCus+=customers[i]*grumpy[i];
        }
        maxUnsatCus=currUnSatCus;
        int i=0,j=minutes;
        while(j<n){
            currUnSatCus+=customers[j]*grumpy[j];
            currUnSatCus-=customers[i]*grumpy[i];
            maxUnsatCus=max(maxUnsatCus,currUnSatCus);
            i++;
            j++;
        }
        int total=maxUnsatCus;
        for(int i=0;i<n;i++){
            total+=customers[i]*(1-grumpy[i]);
        }
        return total;
    }
};
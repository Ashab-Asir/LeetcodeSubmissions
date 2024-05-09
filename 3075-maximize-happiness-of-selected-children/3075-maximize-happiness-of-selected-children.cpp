class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int n=happiness.size();
        int sum=0;
        for(int i=n-1;i>=0;i--){
            if(k>0){
                int num=(happiness[i]-(n-i-1));
                sum+=(num>0?num:0);
                
                k--;
            } 
        }
        return sum;
    }
};
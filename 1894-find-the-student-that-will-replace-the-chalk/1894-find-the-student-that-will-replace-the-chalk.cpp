class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int ind=0;
        long long sum=0;
        int n=chalk.size();
        for(int i=0;i<n;i++){
            sum+=chalk[i];
        }
        k=k%sum;
        while(chalk[ind%n]<=k){
            k=k-chalk[ind%n];
            ind++;
        }
        return ind%n;
    }
};
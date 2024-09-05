class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        cout<<m<<endl;
        int sum=0;
        for(int i=0;i<m;i++){
            sum+=rolls[i];
        }
        cout<<sum<<endl;
        int missing_num=mean*(n+m)-sum;
        if(missing_num<0){
            return {};
        }
        if(missing_num/6>n){
            return {};
        }
        int avg=missing_num/n;
        int mod=missing_num%avg;
        cout<<mod;
        vector<int>ans;
        int extra=missing_num-n*avg;
        if(avg<6 && extra>0){
             while(extra--){
            ans.push_back(avg+1);
            n--;
        }
        }
        else if(avg>=6&& extra>0){
            return {};
        }
       
        while(n--){
            ans.push_back(avg);
        }
        return ans;
    }
};
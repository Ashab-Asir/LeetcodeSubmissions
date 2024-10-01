class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            int rem=(abs(arr[i]))%k;
            mp[rem]++;
        }
        if(mp[0]%2!=0){
            return false;
        }
        for(int i=1;i<=k/2;i++){
            int remaining =k-i;
            if(mp[remaining]!=mp[i]){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<double,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[(double)arr[i]/arr[j]]={arr[i],arr[j]};
            }
        }
        vector<vector<int>>temp;
        for(auto x:mp){
            temp.push_back(x.second);
        }
        return temp[k-1];
    }
};
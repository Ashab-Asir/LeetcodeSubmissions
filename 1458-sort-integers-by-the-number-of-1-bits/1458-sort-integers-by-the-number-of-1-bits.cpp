class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>ans;
        for(int i=0;i<arr.size();i++){
            int n=arr[i],cnt=0;
            while(n!=0){
                if(n&1){
                    cnt++;
                }
                n=n>>1;
            }
            pair<int,int>temp;
            temp.first=cnt;
            temp.second=arr[i];
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        vector<int>ans2;
        for(int i=0;i<ans.size();i++){
            ans2.push_back(ans[i].second);
        }
        return ans2;
    }
};
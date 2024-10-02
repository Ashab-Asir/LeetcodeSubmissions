class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int rank=1;
        vector<int>ans(arr.size(),0);
        for(auto element:mp){
        
            cout<<element.first<< " ";
            for(int i=0;i<element.second.size();i++){
                int ind=element.second[i];
                ans[ind]=rank;
            }
            rank++;
        }
        return ans;
    }
};
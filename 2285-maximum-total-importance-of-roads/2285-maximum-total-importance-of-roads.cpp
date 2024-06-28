class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int x=roads.size();
        map<int,int>mp;
        for(int i=0;i<x;i++){
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        long long mul=n;
        vector<int>vec;
        for(auto it:mp){
            vec.push_back(it.second);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        long long ans=0;
        for(int i=0;i<vec.size();i++){
            long long num=(mul*vec[i]);
            ans+=num;
            mul--;
        }
        return ans;
    }
};
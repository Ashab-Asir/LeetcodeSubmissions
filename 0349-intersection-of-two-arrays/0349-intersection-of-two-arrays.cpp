class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int i=0,j=0;
       set<int>ans;
       vector<int>vis(nums2.size(),0);
       for(int i=0;i<nums1.size();i++){
           for(j=0;j<nums2.size();j++){
               if(nums1[i]==nums2[j]&& vis[j]!=1){
                   ans.insert(nums1[i]);
                   vis[j]=1;
                   break;
               }
           }
       }
       vector<int>ans1;
       for(auto it:ans){
           ans1.push_back(it);
       }
       return ans1;
    }
};
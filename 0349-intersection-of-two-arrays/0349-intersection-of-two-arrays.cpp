class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int i=0,j=0;
    set<int>ans;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    while(i<nums1.size()&& j<nums2.size()){
        if(nums1[i]==nums2[j]){
            ans.insert(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    vector<int>ans1;
    for(auto it:ans){
        ans1.push_back(it);
    }
    return ans1;
    }
};
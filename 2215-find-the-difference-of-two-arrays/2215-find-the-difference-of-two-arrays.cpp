class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>st1,st2;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                st1.insert(nums1[i]);
            }
        }
        for(int i=0;i<m;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(nums1[j]==nums2[i]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                st2.insert(nums2[i]);
            }
        }
        vector<int>vec1,vec2;
        for(auto it:st1){
            vec1.push_back(it);
        }
        for(auto it:st2){
            vec2.push_back(it);
        }
        return {vec1,vec2};
    }
};
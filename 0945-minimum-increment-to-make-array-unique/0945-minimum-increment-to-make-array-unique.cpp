class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        stack<int>st;
        st.push(nums[0]);
        int ans=0;
        for(int i=1;i<nums.size();i++){
            int num=nums[i];
            while(st.top()>=num){
                num++;
                ans++;
            }
            st.push(num);
        }
        return ans;
        
    }
};
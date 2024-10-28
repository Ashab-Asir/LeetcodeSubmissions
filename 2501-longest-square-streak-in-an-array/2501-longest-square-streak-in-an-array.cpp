class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            int x=nums[i];
            int sqrtRoot=sqrt(x);
            int num;
            if(sqrtRoot*sqrtRoot==x){
                num=x;
            }
            while(true){ 
                if(st.find(num)!=st.end()){
                    cnt++;
                    sqrtRoot=sqrt(num);
                    if(sqrtRoot*sqrtRoot==num){
                        num=sqrt(num);
                    }
                    else{
                        maxi=max(cnt,maxi);
                        break;
                    }
                    
                }
                else{
                    maxi=max(cnt,maxi);
                    cnt=0;
                    break;
                }
            }
        }
        return maxi<=1?-1:maxi;
    }
};
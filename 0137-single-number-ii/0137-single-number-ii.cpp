class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<=31;k++){
            int temp=1<<k;
            int cntZero=0,cntOne=0;
            for(int num:nums){
                if((num&temp)==0){
                    cntZero++;
                }
                else{
                    cntOne++;
                }
            }
            if(cntOne%3==1){
                result=result|(temp);
            }
            else{

            }
        }
        return result;
    }
};
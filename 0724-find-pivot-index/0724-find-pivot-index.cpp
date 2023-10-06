class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot=0;
        if(pivot-1<0){
            int leftSum=0,rightSum=0;
            for(int i=pivot+1;i<nums.size();i++){
                rightSum+=nums[i];
            }
            if(leftSum==rightSum){
                return 0;
            }
            else{
                pivot++;
            }
        }
        while(pivot<nums.size()){
                int leftSum=0,rightSum=0;
            //left sum
           for(int i=0;i<pivot;i++){
               leftSum+=nums[i];
           }
            //right sum
            for(int i=pivot+1;i<nums.size();i++){
                rightSum+=nums[i];
            }
            if(leftSum==rightSum){
                return pivot;
            }
                pivot++;
            }
        return -1;
    }
};
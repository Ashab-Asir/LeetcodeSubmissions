class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            Xor^=nums[i];
        }
        int cnt=0;
        while(Xor){
            if(Xor&1){
                break;
            }
            else{
                cnt++;
                Xor=Xor>>1;
            }
        }
        int grpA=0,grpB=0;
        for(int i=0;i<n;i++){
            if((nums[i]>>cnt)&1){
                grpA=grpA^nums[i];
            }
            else{
                grpB=grpB^nums[i];
            }
        }
        return {grpA,grpB};
    }
};
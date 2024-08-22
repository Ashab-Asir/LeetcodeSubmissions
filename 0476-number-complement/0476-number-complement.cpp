class Solution {
public:
    int findComplement(int num) {
        int mask=0;
        int num1=num;
        while(num!=0){
            mask=(mask<<1)|1;
            num=num>>1;
        }
        int ans=(~num1)&mask;
        return ans;
    }
};
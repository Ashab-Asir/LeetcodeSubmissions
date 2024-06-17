class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0,j=c;
        while(i<=j){
            if(i*i+j*j==c){
                return true;
            }
            else if(2*i*i==c){
                return true;
            }
            else if(2*j*j==c){
                return true;
            }
            else if(i*i+j*j>c){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
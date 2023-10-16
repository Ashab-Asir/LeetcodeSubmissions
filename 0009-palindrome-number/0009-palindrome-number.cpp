class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        int rev=0;
        if(x<0){
            return false;
        }
        while(n!=0){
            int digit=n%10;
            if(rev<INT_MIN/10 || rev>INT_MAX/10){
                return false;
            }
            rev=(rev*10)+digit;
            n=n/10;
        }
        if(rev==x){
            return true;
        }
        else{
            return false;
        }
    }
};
class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int carry=0;
        int cnt=0;
        for(int i=n-1;i>0;i--){
            if((s[i]-'0'+carry)%2==1){
                cnt+=2;
                carry=1;
            }
            else{
                cnt++;
            }
        }
        return cnt+carry;
    }
};
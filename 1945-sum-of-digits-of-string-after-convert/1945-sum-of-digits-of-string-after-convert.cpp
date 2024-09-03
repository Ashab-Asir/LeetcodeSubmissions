class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(int i=0;i<s.size();i++){
            int num=s[i]-'a'+1;
            temp+=to_string(num);
        }
        int sum=0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i]-'0';
        }
        k--;
        while(k--){
            int tempSum=0;
            while(sum){
                int digit=sum%10;
                tempSum+=digit;
                sum=sum/10;
            }
            sum=tempSum;
        }
        return sum;
    }
};
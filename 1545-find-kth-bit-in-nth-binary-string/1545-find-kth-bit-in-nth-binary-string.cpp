class Solution {
public:
    string inverted(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        n=n-1;
        int i=2;
        while(n--){
            string invertStr=inverted(s);
            reverse(invertStr.begin(),invertStr.end());
            s=s+'1'+invertStr;
        }
        return s[k-1];
    }
};
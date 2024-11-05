class Solution {
public:
    int cnt=0;
    int minChanges(string s) {
        for(int i=0;i<s.size();i+=2){
            if(s[i]!=s[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            int num=abs((s[i]-'a')-(s[i+1]-'a'));
            ans+=num;
        }
        return ans;
    }
};
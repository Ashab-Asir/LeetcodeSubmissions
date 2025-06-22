class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int size=s.size();
        vector<string>ans;
        if(size%k!=0){
            for(int i=1;i<=k-(size%k);i++){
                s+=fill;
            }
        }
        for(int i=0;i<s.size();i+=k){
            string sub=s.substr(i,k);
            ans.push_back(sub);
        }
        return ans;
    }
};
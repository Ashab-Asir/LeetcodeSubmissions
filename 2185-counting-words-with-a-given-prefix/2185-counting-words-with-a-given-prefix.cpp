class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size(),cnt=0;
        for(int i=0;i<n;i++){
            string str=words[i].substr(0,pref.size());
            if(str==pref){
                cnt++;
            }
        }
        return cnt;
    }
};
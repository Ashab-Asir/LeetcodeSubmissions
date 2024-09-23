class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<char>st;
        for(auto word:dictionary){
            for(auto ch:word){
                st.insert(ch);
            }
        }
        int ans=0;
        for(auto ch:s){
            if(st.count(ch)==0){
                ans++;
            }
        }
        return ans;
    }
};
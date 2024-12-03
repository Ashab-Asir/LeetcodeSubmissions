class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        set<int>st;
        for(auto x:spaces){
            st.insert(x);
        }
        for(int i=0;i<s.size();i++){
            if(st.find(i)!=st.end()){
                ans+=' ';
                ans+=s[i];
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};
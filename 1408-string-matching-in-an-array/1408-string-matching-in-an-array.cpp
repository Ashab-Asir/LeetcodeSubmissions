class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        set<string>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(words[j].find(words[i])!=string::npos){
                    st.insert(words[i]);
                }
            }
        }
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};
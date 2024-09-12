class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>st;
        for(auto x:allowed){
            st.insert(x);
        }
        int cnt=0;
        for(auto word:words){
            int flag=0;
            for(auto x:word){
                if(st.find(x)==st.end()){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int t[52];
    int solve(int i,string s,set<string>st,int n){
        if(i>=n){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int result=1+solve(i+1,s,st,n);
        for(int j=i;j<n;j++){
            string str=s.substr(i,j-i+1);
            if(st.count(str)){
                result=min(result,solve(j+1,s,st,n));
            }
        }
        return t[i]=result;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(t,-1,sizeof(t));
        int n=s.size();
        set<string>st(begin(dictionary),end(dictionary));
        return solve(0,s,st,n);
    }
};
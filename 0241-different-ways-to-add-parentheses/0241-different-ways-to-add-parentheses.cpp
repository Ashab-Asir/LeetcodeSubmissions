class Solution {
public:
    vector<int>solve(string s){
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+'|| s[i]=='-'|| s[i]=='*'){
                vector<int>left=solve(s.substr(0,i));
                vector<int>right=solve(s.substr(i+1));
                for(auto x:left){
                    for(auto j:right){
                        if(s[i]=='+'){
                            ans.push_back(x+j);
                        }
                        else if(s[i]=='-'){
                            ans.push_back(x-j);
                        }
                        else{
                            ans.push_back(x*j);
                        }
                    }
                }
            }
        }
        if(ans.size()==0){
            ans.push_back(stoi(s));
            return ans;
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
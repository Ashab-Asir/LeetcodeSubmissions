class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(ans.size()==0 || (ans.back()==s[i]&& cnt<2)||s[i]!=ans.back()){
                if(ans.size()==0 || s[i]==ans.back() ){
                    cnt++;
                }
                else{
                    cnt=1;
                }
                ans+=s[i];
            }
        }
        return ans;
    }
};
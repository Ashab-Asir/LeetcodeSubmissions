class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size();
        for(auto vec:shifts){
            int start=vec[0];
            int end=vec[1];
            int dir=vec[2];
            for(int i=start;i<=end;i++){
                if(dir==1){
                    if(s[i]=='z'){
                        s[i]=s[i]+1-26;
                    }
                    else{
                        s[i]=s[i]+1;
                    }
                }
                else{
                    if(s[i]=='a'){
                        s[i]=s[i]-1+26;
                    }
                    else{
                        s[i]=s[i]-1;
                    }
                }
            }
        }
        return s;
    }
};
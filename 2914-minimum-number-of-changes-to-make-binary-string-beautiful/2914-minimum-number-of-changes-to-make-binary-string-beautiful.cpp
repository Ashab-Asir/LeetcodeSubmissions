class Solution {
public:
    int minChanges(string s) {
        int cntOne=0,cntZero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                cntZero++;
            }
            else{
                cntOne++;
            }
        }
        if(cntOne==0 ||cntZero==0){
            return 0;
        }
        return min(cntZero,cntOne);
    }
};
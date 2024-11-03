class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        if(s==goal){
            return true;
        }
        string tempStr1=s,tempStr2=goal;
        sort(tempStr1.begin(),tempStr1.end());
        sort(tempStr2.begin(),tempStr2.end());
        if(tempStr1!=tempStr2){
            return false;
        }
        reverse(s.begin(), s.end());
        while (true) {
            goal.pop_back();
            s.pop_back();
            if(s.size()==0){
                return false;
            }
            string temp = s;
            reverse(s.begin(), s.end());
            if (s == goal) {
                return true;
            }
            else{
                s=temp;
            }
        }
        return false;
    }
};
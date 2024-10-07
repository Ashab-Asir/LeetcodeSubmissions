class Solution {
public:
    int minLength(string s) {
        while (true) {
            int pos1 = s.find("AB");
            int pos2 = s.find("CD");
            if (pos1 != string::npos) {
                string newStrBefore = s.substr(0, pos1);
                string newStrAfter = s.substr(pos1 + 2);
                s = newStrBefore + newStrAfter;
            }
            else if(pos2!= string::npos) {
                string newStrBefore = s.substr(0, pos2);
                string newStrAfter = s.substr(pos2 + 2);
                s = newStrBefore + newStrAfter;
            }
            else{
                break;
            }
        }
        
        cout<<s;
        return s.size();
    }
};
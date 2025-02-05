class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;

        string temp1=s1,temp2=s2;
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1!=temp2){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
        }
        if(cnt==2 || cnt==0){
            return true;
        }
        return false;
    }
};
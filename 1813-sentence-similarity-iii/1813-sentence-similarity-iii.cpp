class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size()){
            swap(s1,s2);
        }
        vector<string>vec1,vec2;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string token;
        while(ss1>>token){
            vec1.push_back(token);
        }
        while(ss2>>token){
            vec2.push_back(token);
        }
        int i=0,j=vec1.size()-1,k=0,l=vec2.size()-1;
        while(i<vec1.size() && k<vec2.size() && vec1[i]==vec2[k]){
            i++;
            k++;
        }
        while(l>=k&& vec1[j]==vec2[l] ){
            j--;
            l--;
        }
        if(k>l){
            return true;
        }
        return false;
    }
};
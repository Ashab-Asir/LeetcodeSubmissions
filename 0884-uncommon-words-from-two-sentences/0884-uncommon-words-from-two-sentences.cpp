class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>set1,set2;
        string str1="",str2="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                set1.push_back(str1);
                str1="";
            }
            else{   
                str1+=s1[i];
            }
        }
        set1.push_back(str1);
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                set2.push_back(str2);
                str2="";
            }
            else{   
                str2+=s2[i];
            }
        }
        set2.push_back(str2);
        for(int i=0;i<set2.size();i++){
            cout<<set2[i];
        }
        map<string,int>mp1,mp2;
        for(auto str:set1){
            mp1[str]++;
        }
         for(auto str:set2){
            mp2[str]++;
        }
        vector<string>ans;
        for(auto x:mp1){
            if(x.second==1 && mp2.find(x.first)==mp2.end()){
                ans.push_back(x.first);
            }
        }
         for(auto x:mp2){
            if(x.second==1 && mp1.find(x.first)==mp1.end()){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string,int>mp;
        vector<string>s;
        for(auto x:dictionary){
            mp[x]++;
        }
        string temp="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                s.push_back(temp);
                temp="";
            }
            else{
                temp+=sentence[i];
            }
        }
        s.push_back(temp);
        string ans;
        for(int i=0;i<s.size();i++){
            string temp="";
            for(auto c:s[i]){
                temp+=c;
                if(mp.find(temp)!=mp.end()){
                    s[i]=temp;
                    break;
                }
            }
        }
        for(int i=0;i<s.size();i++){
            ans+=s[i];
            ans+=' ';
        }
        return ans.substr(0,ans.size()-1);

    }
};
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        map<int,string>mp;
        string str="";
        int index=1;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                mp[index]=str;
                str="";
                index++;
            }
            else{
                str+=sentence[i];
            }
        }
        mp[index]=str;
        for(auto x:mp){
          string word=x.second;
          string prefix=word.substr(0,searchWord.size());
          if(prefix==searchWord){
            return x.first;
          }
        }
        return -1;
    }
};
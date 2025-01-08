class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[i].size()>words[j].size()){
                    continue;
                }
                string suffix=words[j].substr(0,words[i].size());
                string prefix=words[j].substr(words[j].size()-words[i].size(),words[i].size());
                if(suffix==words[i] && prefix==words[i]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
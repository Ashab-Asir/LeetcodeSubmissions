class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        int count[26]={0};
        for(auto ch:words[0]){
            count[ch-'a']++;
        }
        for(int i=1;i<n;i++){
            int temp[26]={0};
            for(auto ch:words[i]){
                temp[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                count[i]=min(count[i],temp[i]);
            }
        }
        for(int i=0;i<26;i++){
            int c=count[i];
            while(c--){
                ans.push_back(string(1,'a'+i));
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for(auto str:folder){
            cout<<str<<" ";
        }
        cout<<endl;
        for (int i = 1; i < folder.size(); i++) {
            string prev = ans.back();
            int prevCnt=ranges::count(prev,'/');
            int currCnt=ranges::count(folder[i],'/');
            if (folder[i].size() == prev.size() || prevCnt==currCnt) {
                ans.push_back(folder[i]);
            }
            else if(folder[i].size() > prev.size()){
                string sub=folder[i].substr(0,prev.size());
                if(sub==prev){
                    continue;
                }
                else{
                    ans.push_back(folder[i]);
                }
            }
            else{
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
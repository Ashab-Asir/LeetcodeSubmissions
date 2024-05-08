class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>copy;
        copy=score;
        map<int,string>mp;
        sort(copy.begin(),copy.end());
        reverse(copy.begin(),copy.end());
        for(int i=0;i<copy.size();i++){
            if(i==0){
                mp[copy[i]]="Gold Medal";
            }
            else if(i==1){
                mp[copy[i]]="Silver Medal";
            }
            else if(i==2){
                 mp[copy[i]]="Bronze Medal";
            }
            else{
                mp[copy[i]]=to_string(i+1);
            }
        }
        vector<string>ans(score.size());
        for(int i=0;i<score.size();i++){
            ans[i]=mp[score[i]];
        }
        return ans;
    }
};
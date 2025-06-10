class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<int>oddfreq,evenfreq;
        for(auto x:mp){
            if((x.second)%2==0){
                evenfreq.push_back(x.second);
            }
            else{
                oddfreq.push_back(x.second);
            }
            
        }
        sort(evenfreq.begin(),evenfreq.end());
        sort(oddfreq.begin(),oddfreq.end());
        return oddfreq[oddfreq.size()-1]-evenfreq[0];
    }
};
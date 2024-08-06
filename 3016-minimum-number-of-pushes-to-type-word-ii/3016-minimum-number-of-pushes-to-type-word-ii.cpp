class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        for(char ch:word){
            mp[ch]++;
        }
        vector<int>freq;
        for(auto it:mp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int cnt=0,ans=0;
        for(auto x:freq){
            cnt++;
            if(cnt<=8){
                ans+=(x);
            }
            else if(cnt<=16){
                ans+=(2*x);
            }
            else if(cnt<=24){
                ans+=(3*x);
            }
            else{
                ans+=(4*x);
            }
        }
        return ans;
    }
};
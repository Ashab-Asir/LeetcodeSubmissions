class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length() , start = 0 , ans = INT_MAX , cnt = 0;
        unordered_map<char,int> mp;
        for(auto &ch : s)
            mp[ch]++;
        
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k)
            return -1;
        for(int i=0 ; i<n ; i++){
            mp[s[i]]--;
            cnt++;
            
            while(mp[s[i]] < k){
                mp[s[start++]]++;
                cnt--;
            }
            ans = min(ans,n-cnt);
        }
        return ans;
    }
};
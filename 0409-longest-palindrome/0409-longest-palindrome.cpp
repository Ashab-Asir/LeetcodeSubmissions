class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        int even=0,odd=0,flag=0;
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second%2==0){
                even+=(it.second);
            }
            else{
                flag=1;
                odd+=(it.second-1);
            }
        }
       return even+odd+flag;
    }
};
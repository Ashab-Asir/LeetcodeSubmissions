class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
        }
        int i=0,j=0;
        while(j<s2.size()){
            freq2[s2[j]-'a']++;
            if(j-i+1>s1.size()){
                freq2[s2[i]-'a']--;
                i++;
            }
            if(freq1==freq2){
                return true;
            }
            j++;
        }
        return false;
    }
};
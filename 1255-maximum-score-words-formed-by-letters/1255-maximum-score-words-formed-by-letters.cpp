class Solution {
public:
    void solve(int ind,vector<int>& score,vector<string>& words,int &maxScore,map<char,int>&mp,int currentScore){
        maxScore=max(maxScore,currentScore);
        if(ind==words.size()){
            return ;
        }
        int j=0;
        int tempScore=0;
        map<char,int>tempMap=mp;
        while(j<words[ind].size()){
            char ch=words[ind][j];
            tempMap[ch]--;
            tempScore+=score[ch-'a'];
            if(tempMap[ch]<0){
                break;
            }
            j++;
        }
        if(j==words[ind].size()){
            solve(ind+1,score,words,maxScore,tempMap,currentScore+tempScore);
        }
        
        solve(ind+1,score,words,maxScore,mp,currentScore);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        map<char,int>mp;
        for(int i=0;i<letters.size();i++){
            mp[letters[i]]++;
        }
        int maxScore=INT_MIN;
        solve(0,score,words,maxScore,mp,0);
        return maxScore;
    }
};
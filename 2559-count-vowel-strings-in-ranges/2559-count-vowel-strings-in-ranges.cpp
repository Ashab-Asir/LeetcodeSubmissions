class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>cntArr;
        int cnt=0;
        for(int i=0;i<n;i++){
            string word=words[i];
            int startIdx=0;
            int endIdx=words[i].size()-1;
            if((word[startIdx]=='a'||word[startIdx]=='e'
            ||word[startIdx]=='i'||word[startIdx]=='o'
            ||word[startIdx]=='u') 
            &&
            (word[endIdx]=='a'||word[endIdx]=='e'
            ||word[endIdx]=='i'||word[endIdx]=='o'
            ||word[endIdx]=='u')){
                cnt++;
                cntArr.push_back(cnt);
            }
            else{
                cntArr.push_back(cnt);
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
           if(queries[i][0]==0){
                int idx=queries[i][1];
                ans.push_back(cntArr[idx]);
            }
            else{
                int lastidx=queries[i][1];
                int idx=queries[i][0];
                int prevIdx=idx-1;
                ans.push_back(cntArr[lastidx]-cntArr[prevIdx]);
            }
        }
        for(int i=0;i<cntArr.size();i++){
            cout<<cntArr[i];
        }
        cout<<endl;
        return ans;
    }
};
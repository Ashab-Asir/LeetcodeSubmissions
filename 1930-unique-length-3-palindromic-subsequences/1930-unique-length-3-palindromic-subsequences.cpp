class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        int cnt=0;
        set<char>st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }
        int leftIdx=-1,rightIdx=-1;
        for(auto x:st){
            for(int i=0;i<n;i++){
                if(s[i]==x){
                    leftIdx=i;
                    break;
                }
            }
            for(int i=n-1;i>=0;i--){
                if(s[i]==x){
                    rightIdx=i;
                    break;
                }
            }
            set<char>st_1;
            if(leftIdx!=-1 && rightIdx!=-1){
                for(int i=leftIdx+1;i<rightIdx;i++){
                    st_1.insert(s[i]);
                }
            }
            cnt+=st_1.size();
        }
        return cnt;
    }
};
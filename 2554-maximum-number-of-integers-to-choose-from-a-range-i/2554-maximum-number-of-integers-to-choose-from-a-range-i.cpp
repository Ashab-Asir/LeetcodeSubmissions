class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(int i=0;i<banned.size();i++){
            st.insert(banned[i]);
        }
        int sum=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                sum+=i;
                if(sum<=maxSum){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
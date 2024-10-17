class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        priority_queue<int>pq;
        for(int i=0;i<s.size();i++){
            pq.push(s[i]-'0');
        }
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'==pq.top()){
                pq.pop();
            }
            else{
                int topNum=pq.top();
                int j;
                for(j=s.size()-1;j>i;j--){
                    if(topNum==s[j]-'0'){
                        break;
                    }
                }
                swap(s[j],s[i]);
                break;
            }
        }
        return stoi(s);
    }
};
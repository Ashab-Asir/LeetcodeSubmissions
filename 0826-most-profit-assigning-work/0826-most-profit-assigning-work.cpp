class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<profit.size();i++){
            pq.push({profit[i],difficulty[i]});
        }
        int ans=0;
        sort(worker.begin(),worker.end(),greater<int>());
        int i=0;
        while(!pq.empty() &&i<worker.size()){
            if(worker[i]<pq.top().second){
                pq.pop();
            }
            else{
                ans+=pq.top().first;
                i++;
            }
        }
        return ans;
    }
};
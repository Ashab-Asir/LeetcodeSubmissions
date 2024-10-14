class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto num:nums){
            pq.push(num);
        }
        long long scr=0;
        while(k--){
            int maxi=pq.top();
            pq.pop();
            scr+=maxi;
            maxi=ceil(maxi/3.0);
            pq.push(maxi);
        }
        return scr;
    }
};
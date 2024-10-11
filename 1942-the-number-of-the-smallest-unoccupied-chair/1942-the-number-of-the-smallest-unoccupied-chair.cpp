class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        int friendArrivaliTime=times[targetFriend][0];
        vector<int>chairs(n,-1);
        sort(times.begin(),times.end());
        for(auto vec:times){
            int arrival=vec[0];
            int  leaving=vec[1];
            for(int i=0;i<n;i++){
                if(arrival>=chairs[i]){
                    chairs[i]=leaving;
                    if(friendArrivaliTime==arrival){
                        return i;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};
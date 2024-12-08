class Solution {
public:
    int n;
    int t[100001][3];
    int bs(vector<vector<int>>& events,int endTime){
        int l=0;
        int r=n-1;
        int result=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][0]>endTime){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& events,int idx,int cnt){
        if(cnt==2 || idx>=n){
            return 0;
        }
        if(t[idx][cnt]!=-1){
            return t[idx][cnt];
        }
        int nextValidIdx=bs(events,events[idx][1]);
        int take=events[idx][2]+solve(events,nextValidIdx,cnt+1);
        int notTake=solve(events,idx+1,cnt);
        return t[idx][cnt]= max(take,notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(t,-1,sizeof(t));
        n=events.size();
        sort(events.begin(),events.end());
        int cnt=0;
        return solve(events,0,cnt);
    }
};
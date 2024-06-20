class Solution {
public:
    bool isPossible(int mid,vector<int>& position,int m){

        int prev=position[0];
        int cnt=1;
        for(int i=1;i<position.size();i++){
            if(position[i]-prev>=mid){
                prev=position[i];
                cnt++;
            }
            if(cnt==m){
                break;
            }
        }
        return cnt==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1,high=position[n-1]-position[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,position,m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        int i=0;
        while(i<arr.size()){
            if(arr[i]%2!=0){
                cnt++;
                if(cnt==3){
                    return true;
                }
                
            }
            else{
                cnt=0;
            }
            i++;
        }
        return false;
    }
};
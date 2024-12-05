class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0;
        int n=start.size();
        int m=target.size();
        if(start==target){
            return true;
        }
        while(i<start.size() || j<target.size()){
            while(start[i]=='_'){
                i++;
            }
            while(target[j]=='_'){
                j++;
            }
            if(i==n || j==n){
                return i==n && j==n;
            }
            if(start[i]=='R' && i<=j){
                i++;
                j++;
            }
            else if(start[i]=='L' && i>=j){
                i++;
                j++;
            }
            else {
                return false;
            }

        }
       
        return true;
    }
};
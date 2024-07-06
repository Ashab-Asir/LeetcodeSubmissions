class Solution {
public:
    int passThePillow(int n, int time) {
        int dir=1;
        int ind=1;
        while(time>0){
            if(ind+dir>=1 && ind+dir<=n){
                ind+=dir;
                time--;
            }
            else{
                dir*=-1;
            }
        }
        return ind;
    }
};
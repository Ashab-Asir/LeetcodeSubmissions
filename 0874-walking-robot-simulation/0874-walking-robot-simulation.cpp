class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(vector<int> x:obstacles){
            string key=to_string(x[0])+"_"+to_string(x[1]);
            st.insert(key);
        }
        int x=0;
        int y=0;
        int max_dis=0;
        vector<int>dir={0,1};
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-2){
                dir={-dir[1],dir[0]};
            }
            else if(commands[i]==-1){
                dir={dir[1],-dir[0]};
            }
            else{
                for(int j=0;j<commands[i];j++){
                    int newX=x+dir[0];
                    int newY=y+dir[1];
                    string newKey=to_string(newX)+"_"+to_string(newY);
                    if(st.find(newKey)!=st.end()){
                        break;
                    }
                    x=newX;
                    y=newY;
                }
            }
            max_dis=max(max_dis,x*x+y*y);
        }
        return max_dis;
    }
};
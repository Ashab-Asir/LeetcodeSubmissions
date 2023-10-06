class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int>p(arr.size(),0);
        p[0]=arr[0];
        for(int i=1;i<arr.size();i++){
           p[i]=p[i-1]+arr[i];
        }
        int sum=0;
        for(int i=0;i<p.size();i++){
            for(int j=i;j<p.size();j+=2){
                if(i-1>=0){
                    sum=sum+p[j]-p[i-1];
                }
                else{
                    sum=sum+p[j];
                }
            }
        }
        return sum;
    }
};
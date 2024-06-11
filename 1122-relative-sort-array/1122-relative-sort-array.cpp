class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans,notInArr;
        for(int i=0;i<arr1.size();i++){
            auto it=find(arr2.begin(), 
                 arr2.end(), arr1[i]);
                 if(it==arr2.end()){
                    notInArr.push_back(arr1[i]);
                 }
        }
        sort(notInArr.begin(),notInArr.end());
        cout<<endl;
        for(int i=0;i<arr2.size();i++){
            int flag=0;
            for(int j=0;j<arr1.size();j++){
                if(arr1[j]==arr2[i]){
                    ans.push_back(arr1[j]);
                }
            }
        }
        for(int i=0;i<notInArr.size();i++){
            ans.push_back(notInArr[i]);
        }
        return ans;
    }
};
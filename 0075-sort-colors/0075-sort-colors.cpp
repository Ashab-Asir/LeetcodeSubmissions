class Solution {
public:
    void sortColors(vector<int>& arr) {
     int low=0,mid=0,high=arr.size()-1;
    while(mid<=high){
      if(arr[mid]==2){
          swap(arr[high],arr[mid]);
          high--;
      }
      else if(arr[mid]==1){
          mid++;
      }
      else{
          swap(arr[mid],arr[low]);
          low++;
          mid++;
      }
    }
    }
};
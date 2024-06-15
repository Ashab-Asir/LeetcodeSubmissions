class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxArea=INT_MIN;
        while(i<=j){
            int width=j-i;
            int h=min(height[i],height[j]);
            int area=width*h;
            maxArea=max(maxArea,area);
            if(i+1<height.size() && j-1>=0 && height[i]<height[i+1] && height[j]<height[j-1]){
                i++;
                j--;
            }
            else if(i+1<height.size()&& height[i]<height[i+1]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};
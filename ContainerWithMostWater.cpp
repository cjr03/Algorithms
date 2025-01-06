class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        if (right <= 0) return 0;
        int left = 0, maxArea = 0; 
        while(left != right){
            int area = (right - left) * (height[left] >= height[right] ? height[right--] : height[left++]);
            if(area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};

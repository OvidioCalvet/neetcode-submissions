class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, area = 0;

        while(l < r) {
            int h = min(heights[l], heights[r]);
            int currArea = h*(r - l);
            // calculate max 
            area = max(area, currArea);
            // logic for moving ptrs
            if(heights[l] >= heights[r]) r--;
            else l++;
        }
        return area;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {
            int idx = l + (r - l) / 2; 

            if(nums[idx] == target) {
                return idx;
            } else if (nums[idx] > target) {
                r = idx - 1;
            } else if (nums[idx] < target) {
                l = idx + 1;
            }
        }
        
        return -1;
    }
};

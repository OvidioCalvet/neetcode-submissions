class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            // positive numbers cant make zero
            if(nums[i] > 0) break;
            // move i ptr past duplicates to avoid duplicate triplets
            if(i > 0 && nums[i] == nums[i-1]) continue;
            // l and r ptrs
            int l = i + 1, r = nums.size() - 1;
            int target = -1*nums[i];
            // 2 sum on subarray
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum > target) r--;
                else if(sum < target) l++;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }
            }
        }
        return res;
    }
};
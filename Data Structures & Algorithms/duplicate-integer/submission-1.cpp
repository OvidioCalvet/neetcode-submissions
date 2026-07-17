class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        std::unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            
            if(freq.find(nums[i]) == freq.end()) {
                freq.emplace(nums[i], 1);
                continue;
            }
            return true;
        }

        return false;
    }
};
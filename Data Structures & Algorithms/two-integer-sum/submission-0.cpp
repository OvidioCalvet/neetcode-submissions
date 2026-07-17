class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> table;

        for(int i = 0; i < nums.size(); i++) {
            
            // calculate the compliment num
            int compliment = target - nums[i];

            // check if compliment exists in table
            if(table.find(compliment) != table.end()) {
                // if compliment exists return indices
                return {table[compliment], i};
            }
            // else add value i to table 
            table.emplace(nums[i], i);
        }
    }
};

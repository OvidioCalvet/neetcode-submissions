class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // result vector
        vector<int> result;
        // get index of each value
        for(int i = 0; i < nums.size(); i++) {
            // product integer
            int prod = 1;
            // second iteration multiplying every number except at index i
            for(int j = 0; j < nums.size(); j++) {
                // skip index i
                if(i == j) continue;

                prod *= nums[j];
            }
            result.push_back(prod);
        }
        return result;
    }
};
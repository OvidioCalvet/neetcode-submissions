class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        vector<int> res;

        for(int i = 0; i < numbers.size(); i++) {
            // find complement at curr num
            int complement = target - numbers[i];

            // check for complement in map
            if(map.find(complement) != map.end()) {
                res.push_back(map[complement]+1);
                res.push_back(i+1);
                return res;
            }

            map[numbers[i]] = i;
        }
        return {};
    }
};
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // create dictionary with element freq
        for(auto& i : nums) {
            if (freq.find(i) != freq.end())
                freq[i]++;
            else
                freq.emplace(i, 1);
        }

        // create vec of pairs with their frequency and corr num to be sorted
        vector<pair<int, int>> vec;
        for(auto& i : freq) {
            pair<int, int> temp;
            temp.first = i.second;
            temp.second = i.first;
            vec.push_back(temp);
        }

        // sort in reversed order
        sort(vec.rbegin(), vec.rend());

        // pop elements k time to result and return
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(vec[i].second);
        }

        return result;
    }
};
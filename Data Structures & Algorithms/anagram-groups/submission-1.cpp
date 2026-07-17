class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        std::unordered_map<string, vector<string>> res;

        for(auto& s : strs) {

            // build a vector of 26 indeces with default value of 0
            vector<int> count(26, 0);

            // iterate through each character in the string and create its unique count
            for(auto& c : s)
                count[c - 'a'] += 1;

            // convert the count into a string to be used as a key
            string key = "";
            for(auto& i : count)
                key += i;
            
            // finally add the string to its corr key in the map
            res[key].push_back(s);
        }

        // build a new vector to push all grouped vectors to be returned as the result
        vector<vector<string>> result;
        for(auto& pair : res)
            result.push_back(pair.second);

        return result;
    }
};

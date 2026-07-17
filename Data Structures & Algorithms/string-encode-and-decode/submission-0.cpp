class Solution {
public:

    string encode(vector<string>& strs) {
        // if empty return nothing
        if(strs.size() == 0) return "";

        // vector of sizes and the response as a string
        vector<int> sizes;
        string res = "";

        // iterate through each string and add it size to the vector
        for (string& s : strs)
            sizes.push_back(s.size());

        for (int& size : sizes) {
            res.append(to_string(size));
            res.push_back(',');
        }
        
        // # as a seperator between sizes and message
        res.push_back('#');
        // append each string to the response contiguously
        for(string& s: strs) {
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        // base case
        if (s.empty()) return {};

        // size and str vectors for response
        vector<int> sizes;
        vector<string> strs;

        // extract sizes and strs based on sizes
        int i = 0;
        while (s[i] != '#') {
            int j = i;
            while (s[j] != ',') {
                j++;
            }
            sizes.push_back(stoi(s.substr(i, j-i)));
            i = j + 1;
        }
        i++;
        for(int& size : sizes) {
            strs.push_back(s.substr(i, size));
            i += size;
        }
        return strs;
    }
};